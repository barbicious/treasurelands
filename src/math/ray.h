#pragma once

#include "cglm/ivec3.h"
#include "../util/types.h"

typedef struct {
    vec3 start;
    vec3 end;
    vec3 dir;
} ray_s;

ray_s ray_create(vec3 pos, vec3 dir);
void ray_step(ray_s *ray, f32 scale);
f32 ray_distance(ray_s *ray);