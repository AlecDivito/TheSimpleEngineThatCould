#pragma once

/******************************************************************************
 *
 * Camera3d.h
 * Alec Divito
 * divito.alec@gmail.com
 * Thu Aug 31 20:45:22 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/CursorPositionEvent.h"
#include "event/KeyInputEvent.h"
#include "event/Event.h"

class Camera3d : public Observer
{
    public:
       Camera3d();
       virtual ~Camera3d();
        // update camera
        virtual void Update(Event *);
    protected:
    private:
        // events
        CursorPositionEvent * _cursor;
        KeyInputEvent * _keys;
        // process events
        void _processKeyboard();
        void _processMouseMovement();
        // Calculate front vector
        void _updateCameraVectors();
};
