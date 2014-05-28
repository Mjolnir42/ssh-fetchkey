ssh-fetchkey
============

So, it turns out I was in blissfull ignorance of
ssh-keyscan(1) which does exactly what I wanted
ssh-fetchkey to do.
Major distinguishing feature to ssh-fetchkey is
that it does not suck :)

Well, saves me trouble of updating this here to
a newer version of libssh, making it really useable
etc. So, if you came looking here for something to
fetch ssh public host keys with, check out ssh-keyscan
that comes with OpenSSH.

Have a nice day.


Original Readme:
================

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
