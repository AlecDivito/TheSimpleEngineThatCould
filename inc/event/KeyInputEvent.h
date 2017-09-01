#pragma once

/******************************************************************************
 *
 * KeyInputEvent.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:43 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"
#include "event/Event.h"

class KeyInputEvent : public Event
{
    public:
        int Key;
        int Scancode;
        int Action;
        int Mods;

        static void CreateInstance(Window *);
        static KeyInputEvent * GetInstance();
        virtual ~KeyInputEvent();

        KeyInputEvent(KeyInputEvent const&)        = delete;
        void operator=(KeyInputEvent const&)  = delete;
    protected:
    private:
        KeyInputEvent(Window *);
        static KeyInputEvent * _instance;

        static void key_callback(GLFWwindow * window, int key, int scancode, int action, int mods);
};
