
#include "context.h"

#include "glad/glad.h"

context_s context_create() {
    const window_s window = window_create(1280, 720, string_create("Treasurelands"));

    return (context_s){
        .window = window,
    };
}

void context_run(context_s* context) {
    while (window_is_good(&context->window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.8f, 0.6f, 0.1f, 1.0f);

        window_display(&context->window);
    }

    window_destroy(&context->window);

}
