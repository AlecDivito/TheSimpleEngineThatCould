/******************************************************************************
 *
 * TimeManager.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Mon Nov 20 21:12:56 EST 2017
 * {description}
 *
 *****************************************************************************/

#include "util/TimeManager.h"
#include <GLFW/glfw3.h>

GLfloat TimeManager::DeltaTime = 0.0f;

TimeManager::TimeManager()
{
    _lastFrame = glfwGetTime();
    _currentFrame = 0.0f;
}


TimeManager::~TimeManager()
{

}

void TimeManager::updateDeltaTime() 
{
    _currentFrame = glfwGetTime();
    DeltaTime = _currentFrame - _lastFrame;
    _lastFrame = _currentFrame;
}