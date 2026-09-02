#include "ray.h"

#include <string.h>

#include "cglm/vec3.h"

ray_s ray_create(vec3 pos, vec3 dir) {
    ray_s ray = {};

    memcpy(ray.start, pos, sizeof(vec3));
    memcpy(ray.end, pos, sizeof(vec3));
    memcpy(ray.dir, dir, sizeof(vec3));

    return ray;
}

void ray_step(ray_s *ray, f32 scale) {
    f32 yaw = glm_rad(ray->dir[0] + 90.0f);
    f32 pitch = glm_rad(-ray->dir[1]);

    ray->end[0] -= (f32)cos(yaw) * scale;
    ray->end[1] -= (f32)tan(pitch) * scale;
    ray->end[2] -= (f32)sin(yaw) * scale;
}

f32 ray_distance(ray_s *ray) {
    return glm_vec3_distance(ray->start, ray->end);
}
