/*
 * Use:
 *
 * % ./ssh-fetchkey localhost 2> localhost.pub
 * Public Key Hash: 0c:32:c8:95:77:d0:02:f6:51:fe:9d:55:cf:c5:76:92
 * % ssh-keygen -l -f localhost.pub
 * 2048 0c:32:c8:95:77:d0:02:f6:51:fe:9d:55:cf:c5:76:92  localhost (RSA)
 * % ssh-keygen -l -f /etc/ssh/ssh_host_rsa_key.pub
 * 2048 0c:32:c8:95:77:d0:02:f6:51:fe:9d:55:cf:c5:76:92  comment (RSA)
 *
 */

#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include "base64.h"

int main(int argc, char *argv[])
{
  if (argc != 2) {
    fprintf(stderr, "usage: %s ipaddr|host\n", argv[0]);
    exit(1);
  }

  ssh_session ssh_sess;
  ssh_string ssh_keystr;
  int rc, port = 22;
  size_t slen, hlen;
  const char* keystr = NULL;
  unsigned char* hash = NULL;
  char* b64str;
  int* b64len;
  char buf[10]; // used by ssh_print_hexa()

  ssh_sess = ssh_new();
  if (ssh_sess == NULL) {
    exit(1);
  }

  ssh_options_set(ssh_sess, SSH_OPTIONS_HOST, argv[1]);
  ssh_options_set(ssh_sess, SSH_OPTIONS_PORT, &port);

  rc = ssh_connect(ssh_sess);
  if (rc != SSH_OK) {
    fprintf(stderr, "Error connecting to %s: %s\n",
            argv[1], ssh_get_error(ssh_sess));
    exit(1);  
  }

  ssh_keystr = ssh_get_pubkey(ssh_sess);
  slen = ssh_string_len(ssh_keystr);
  keystr = ssh_string_to_char(ssh_keystr);
  if (keystr == NULL) {
    exit(1);
  }

  b64str = base64(keystr, slen, b64len);
  fprintf(stderr,"ssh-rsa %s %s\n", b64str, argv[1]);

  hlen = ssh_get_pubkey_hash(ssh_sess, &hash);
  ssh_print_hexa("Public Key Hash", hash, hlen);

  ssh_clean_pubkey_hash(&hash);
  ssh_string_free(ssh_keystr);
  ssh_disconnect(ssh_sess);
  ssh_free(ssh_sess);
  exit(0);
};

