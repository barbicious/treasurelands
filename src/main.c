#include <stdio.h>
#include <stdlib.h>

#include "context.h"
#include "util/types.h"

s32 main() {
    context_s context = context_create();
    context_run(&context);
    return EXIT_SUCCESS;
}
