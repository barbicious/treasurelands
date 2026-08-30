#pragma once

#include "core/window.h"

typedef struct {
} context_s;

context_s context_create();

void context_run(context_s *context);
