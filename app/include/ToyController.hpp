//
// Created by teodora on 18.7.25..
//

#ifndef TOYCONTROLLER_HPP
#define TOYCONTROLLER_HPP
#include <engine/core/Controller.hpp>

namespace app {

class ToyController : public engine::core::Controller {
public:
    void initialize() override;
    void poll_events() override;
    void update() override;

    void trigger_movement();
    void toggle_spotlight();

};

} // app

#endif //TOYCONTROLLER_HPP
