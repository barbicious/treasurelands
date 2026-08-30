#pragma once
#include "core/window.h"

typedef struct {
    window_s window;
} context_s;

context_s context_create();
void context_run(context_s* context);
