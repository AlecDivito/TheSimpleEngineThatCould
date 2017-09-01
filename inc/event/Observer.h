#pragma once

/******************************************************************************
 *
 * Observer.h
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Sep  1 11:55:22 EDT 2017
 * {description}
 *
 *****************************************************************************/

class Event;

class Observer
{
    public:
       virtual ~Observer();
       virtual void Update(Event *) = 0;
    protected:
       Observer();
    private:
};
