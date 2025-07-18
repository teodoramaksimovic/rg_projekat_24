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
        WAITING,
        LAMP_OFF
    };
    void initialize() override;
    void poll_events() override;
    void update() override;

    void trigger_movement();
    void toggle_spotlight();

    float get_toy_offset() const { return toyOffset; }
    bool is_spotlight_enabled() const { return spotlightEnabled; }
    bool should_draw_toy() const { return currentState != State::STILL; }

private:
    State currentState;
    float toyOffset;
    float moveTimer;
    bool spotlightEnabled;

    void update_still();
    void update_moving();
    void update_waiting();
    void update_lamp_off();

    void transition_to_state(State newState);
};

} // app

#endif //TOYCONTROLLER_HPP
