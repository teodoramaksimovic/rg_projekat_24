//
// Created by teodora on 18.7.25..
//

#include "ToyController.hpp"
#include "engine/platform/PlatformController.hpp"
#include "spdlog/spdlog.h"

#include <engine/core/Controller.hpp>
#include "engine/platform/PlatformController.hpp"

namespace app {

void ToyController::initialize() {
    transition_to_state(State::STILL);
}
void ToyController::poll_events() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();

    if (platform->key(engine::platform::KeyId::KEY_R).state() == engine::platform::Key::State::JustPressed && spotlightEnabled) {
        trigger_movement();
    }

    if (platform->key(engine::platform::KeyId::KEY_L).state() == engine::platform::Key::State::JustPressed) {
        toggle_spotlight();
    }
}
void ToyController::update() {
}
void ToyController::trigger_movement() {
    if (currentState == State::STILL || currentState == State::MOVING) {
        if (currentState == State::STILL) {
            spotlightEnabled = true;
            transition_to_state(State::MOVING);
        }
        toyOffset += 0.07;

        if (toyOffset >= 0.91f) {
            toyOffset = 0.91f;
        }
    }
}
void ToyController::toggle_spotlight() {
    if (currentState == State::STILL) {
        spotlightEnabled = !spotlightEnabled;
    } else if (currentState == State::MOVING || currentState == State::WAITING) {
        spotlightEnabled = false;
        toyOffset = 0.0f;
        transition_to_state(State::STILL);
        spdlog::info("Toy: FSM interrupted, returning to IDLE");
    }
}
void ToyController::transition_to_state(State newState) {
    currentState = newState;
    moveTimer = 0.0f;

    switch (newState) {
        case State::STILL:
            spdlog::info("Igracka -> STILL");
            break;
        case State::MOVING:
            spdlog::info("Igracka -> MOVING");
            break;
        case State::WAITING:
            spdlog::info("Igracka -> WAITING");
            break;
    }
}
}// namespace app