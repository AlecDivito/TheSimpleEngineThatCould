/******************************************************************************
 *
 * Event.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 11:57:42 EDT 2017
 * {description}
 *
 *****************************************************************************/

#include "event/Event.h"
#include <iostream>
Event::Event()
{
    _observers = new std::list<Observer *>;
}


Event::~Event()
{
    delete _observers;
}

void Event::Attach(Observer * o)
{
    _observers->push_back(o);
}

void Event::Detach(Observer * o)
{
    _observers->remove(o);
}

void Event::Notify()
{
    std::list<Observer *>::const_iterator i;
    for (i = _observers->begin(); i != _observers->end(); ++i)
    {
        (*i)->Update(this);
    }
}
