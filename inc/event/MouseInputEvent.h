#pragma once

/******************************************************************************
 *
 * MouseInputEvent.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:50 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"
#include "event/Event.h"

class MouseInputEvent : public Event
{
    public:
        int Button;
        int Action;
        int Mods;

        virtual ~MouseInputEvent();
        static void CreateInstance(Window *);
        static MouseInputEvent * GetInstance();

        MouseInputEvent(MouseInputEvent const&)      = delete;
        void operator=(MouseInputEvent const&)  = delete;
    protected:
    private:
        MouseInputEvent(Window *);
        static MouseInputEvent * _instance;

        static void mouse_button_callback(GLFWwindow * window, int button, int action, int mods);
};
