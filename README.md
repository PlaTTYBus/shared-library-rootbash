# shared-library-rootbash

The shared library "utils.so" copies the /bin/bash binary into /tmp/rootbash with SUID bit set (must be run as root e.g. from crontab)

## Build
1. Rename utils.so to the expected shared-library name
2. Run `gcc -shared -fPIC -o ./out/utils.so ./utils.c`


## Deploy
Deploy the resulting .so file at the expected location. Could be in:
    - DT_RPATH in the binary (legacy, checked first)
    - LD_LIBRARY_PATH env var (cat /etc/crontab)
    - DT_RUNPATH in the binary (checked after LD_LIBRARY_PATH)
    - /etc/ld.so.cache (built from /etc/ld.so.conf + /etc/ld.so.conf.d/*)
    - Default dirs /lib, /usr/lib (and lib64 variants)

## Run
Run vulnarable binary or wait for the cronjob to run.

Finally:
```bash
/tmp/rootbash -p
```
