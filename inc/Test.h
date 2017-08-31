#pragma once

/******************************************************************************
 *
 * Test.cpp
 * Alec Divito
 * divito.alec@gmail.com
 * Fri Aug 18 13:53:53 EDT 2017
 * {description}
 *
 *****************************************************************************/

class Test
{
    public:
        Test();
        virtual ~Test();
	// asserts
	void areEqual(int, int);
	void areNotEqual(int, int);
    protected:
    private:
};
