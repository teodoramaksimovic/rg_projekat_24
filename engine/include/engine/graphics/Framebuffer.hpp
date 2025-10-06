//
// Created by teodora on 3.9.25..
//

#ifndef MATF_RG_PROJECT_FRAMEBUFFER_HPP
#define MATF_RG_PROJECT_FRAMEBUFFER_HPP
#include <engine/resources/Shader.hpp>

namespace engine::graphics {
class Framebuffer {
    public:
        void setup(int width, int height);
        void begin_rendering();
        void end_rendering(resources::Shader *post_process_shader);
        void clear_default_framebuffer();

    private:
        unsigned int m_frame_buffer_id;
        unsigned int m_color_texture;
        unsigned int m_screen_quad_vao;

        void init_resources(int width, int height);
        unsigned int create_quad();
        void reset();
};
}// namespace engine::graphics


#endif//MATF_RG_PROJECT_FRAMEBUFFER_HPP
