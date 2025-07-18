//
// Created by teodora on 18.7.25..
//

#ifndef TOYCONTROLLER_HPP
#define TOYCONTROLLER_HPP
#include <engine/core/Controller.hpp>

namespace app {

class ToyController : public engine::core::Controller {
public:
    enum class State {
        STILL,
        MOVING,
        WAITING
    };
    void initialize() override;
    void poll_events() override;
    void update() override;

    void trigger_movement();
    void toggle_spotlight();

    bool is_spotlight_enabled() const { return spotlightEnabled; }
    State currentState;
    float toyOffset;
    bool spotlightEnabled;
    void update_still();
    void update_moving();
    void update_waiting();
    void transition_to_state(State newState);
};

} // app

#endif //TOYCONTROLLER_HPP
