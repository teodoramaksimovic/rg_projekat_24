//
// Created by teodora on 18.7.25..
//

#include "ToyController.hpp"
#include "engine/platform/PlatformController.hpp"
#include "spdlog/spdlog.h"

#include "engine/platform/PlatformController.hpp"
#include <engine/core/Controller.hpp>

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
    switch (currentState) {
        case State::STILL:
            update_still();
            break;
        case State::MOVING:
            update_moving();
            break;
        case State::WAITING:
            update_waiting();
            break;
        case State::LAMP_OFF:
            update_lamp_off();
            break;
    }
}
void ToyController::trigger_movement() {
    if (currentState == State::STILL || currentState == State::MOVING) {
        if (currentState == State::STILL) {
            spotlightEnabled = true;
            transition_to_state(State::MOVING);
        }
        toyOffset += 0.07;

        if (toyOffset >= 1.55f) {
            toyOffset = 1.55f;
            transition_to_state(State::WAITING);
        }
    }
}
void ToyController::toggle_spotlight() {
    if (currentState == State::STILL) {
        spotlightEnabled = !spotlightEnabled;
    } else if (currentState == State::MOVING || currentState == State::WAITING || currentState == State::LAMP_OFF) {
        spotlightEnabled = false;
        toyOffset = 0.0f;
        transition_to_state(State::STILL);
    }
}
void ToyController::update_still() {
}
void ToyController::update_moving() {
}
void ToyController::update_waiting() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    moveTimer += platform->dt();

    if (moveTimer >= 2.0f) {
        transition_to_state(State::LAMP_OFF);
    }
}

void ToyController::update_lamp_off() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();
    moveTimer += platform->dt();

    if (moveTimer >= 1.0f) {
        spotlightEnabled = false;
        toyOffset = 0.0f;
        transition_to_state(State::STILL);
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
        case State::LAMP_OFF:
            spdlog::info("Igracka -> LAMP_OFF");
            break;
    }
}
}// namespace app