#pragma once
#include "lvl/level.h"

typedef struct {
    level_s level;
} context_s;

context_s context_create();

void context_run(context_s *context);
