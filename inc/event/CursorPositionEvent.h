#pragma once

/******************************************************************************
 *
 * CursorPositionEvent.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 16:31:10 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "util/Window.h"
#include "event/Event.h"

class CursorPositionEvent : public Event
{
    public:
        double XPos;
        double YPos;

        static void CreateInstance(Window *);
        static CursorPositionEvent * GetInstance();
        virtual ~CursorPositionEvent();

        CursorPositionEvent(CursorPositionEvent const&)  = delete;
        void operator=(CursorPositionEvent const&)  = delete;
    protected:
    private:
        CursorPositionEvent(Window *);
        static CursorPositionEvent * _instance;

        static void cursor_pos_callback(GLFWwindow * window, double xpos, double ypos);
};

