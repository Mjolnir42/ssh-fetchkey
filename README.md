ssh-fetchkey
============

My incredibly bad first C program using libssh
to fetch a remote SSH hostkey.

Outputs the publickey in OpenSSH format on STDERR
and the fingerprint on STDOUT.

Currently written against:
* libssh-4 0.5.2-1ubuntu0.12.04.3
* libssh-dev 0.5.2-1ubuntu0.12.04.3

Since the used version of libssh does not yet have
the option to set the requested hostkey type
(`SSH_OPTIONS_HOSTKEYS`), this really should not be
used at all :)

Slippery when wet yadda yadda.
