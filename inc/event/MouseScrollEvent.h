#pragma once

/******************************************************************************
 *
 * MouseScrollEvent.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:30:55 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"
#include "event/Event.h"

class MouseScrollEvent : public Event
{
    public:
        double XOffset;
        double YOffset;

        static void CreateInstance(Window *);
        static MouseScrollEvent * GetInstance();
        virtual ~MouseScrollEvent();

        MouseScrollEvent(MouseScrollEvent const&)     = delete;
        void operator=(MouseScrollEvent const&)  = delete;
    protected:
    private:
        MouseScrollEvent(Window *);
        static MouseScrollEvent * _instance;

        static void scroll_callback(GLFWwindow * window, double xoffset, double yoffset);
};
