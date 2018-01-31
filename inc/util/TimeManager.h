#pragma once

/******************************************************************************
 *
 * TimeManager.h
 * Alec Divito
 * divito.alec@gmail.com
 * Mon Nov 20 21:12:56 EST 2017
 * {description}
 *
 *****************************************************************************/

#include <GL/glew.h>

class TimeManager
{
    public:
        static GLfloat DeltaTime;

        TimeManager();
        virtual ~TimeManager();

        void updateDeltaTime();

    protected:
    private:
        GLfloat _lastFrame = 0.0f;
        GLfloat _currentFrame = 0.0f;
};
