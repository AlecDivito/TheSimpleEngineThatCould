#pragma once

/******************************************************************************
 *
 * Event.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 11:57:42 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/Observer.h"
#include <list>

class Event
{
    public:
       virtual ~Event();
       virtual void Attach(Observer *);
       virtual void Detach(Observer *);
       virtual void Notify();
    protected:
       Event();
    private:
        std::list<Observer *> * _observers;
};

// 333