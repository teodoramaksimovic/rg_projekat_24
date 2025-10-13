//
// Created by teodora on 4.7.25..
//

#ifndef MAINCONTROLLER_HPP
#define MAINCONTROLLER_HPP
#include <engine/core/Controller.hpp>
#include <engine/graphics/Framebuffer.hpp>

namespace app {

class MainController : public engine::core::Controller {
    void initialize() override;

    bool loop() override;

    void draw_floor();

    void draw_bench();

    void update_camera();

    void update_spotlight_color();

    void update_pp();

    void update() override;

    void begin_draw() override;

    void draw_toy();

    void draw_streetlamp();

    void setup_lighting();

    void draw() override;

    void end_draw() override;

    void toggle_postprocessing();

public:
    std::string_view name() const override {
        return "app:MainController";
    }

private:
    engine::graphics::Framebuffer fb;

    float spotlightRedComponentAmb = 0.2f;
    float spotlightRedComponentDif = 1.0f;
    bool postProcessingEnabled = false;
};

}// namespace app

#endif//MAINCONTROLLER_HPP
