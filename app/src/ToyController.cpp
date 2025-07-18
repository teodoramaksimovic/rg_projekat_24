//
// Created by teodora on 18.7.25..
//

#include "ToyController.hpp"
#include <engine/core/Controller.hpp>
#include "engine/platform/PlatformController.hpp"

namespace app {

void ToyController::initialize() {
}
void ToyController::poll_events() {
    auto platform = engine::core::Controller::get<engine::platform::PlatformController>();

    if (platform->key(engine::platform::KeyId::KEY_R).state() == engine::platform::Key::State::JustPressed) {
        trigger_movement();
    }

    if (platform->key(engine::platform::KeyId::KEY_L).state() == engine::platform::Key::State::JustPressed) {
        toggle_spotlight();
    }
}
void ToyController::update() {
}
void ToyController::trigger_movement() {
}
void ToyController::toggle_spotlight() {
}
} // app