#include "../Headers/Controller.h"

void Abstract::Controller::setWindow(Abstract::Window *window) {
    m_window = window;
}

Abstract::Window *Abstract::Controller::getWindow() {
    return m_window;
}
