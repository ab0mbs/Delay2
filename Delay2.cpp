#include <Arduino.h>
#include <Delay2.h>

Delay2::Delay2()
{
	// Define variables

	/*  Here for reference
	typedef struct {
		unsigned long _timeDelay;
		unsigned long _startMillis;
		int _runCount;
		boolean _running;
	} TimeData;
	*/

	// Create timers array
	TimeData _timers[32];

	// Initialize values in _timers
	for (int i = 0; i < 32; i++)
	{
		_timers[i]._runCount = 0;
		_timers[i]._running = false;
	}
}
boolean Delay2::start(int index, unsigned long timeDelay)
{
	if (_timers[index]._running == false)
	{
		_timers[index]._startMillis = millis();
		_timers[index]._running = true;
		_timers[index]._timeDelay = timeDelay;
	}
	return finished(index);
}
boolean Delay2::start(int index, unsigned long timeDelay, int runTime)
{
	if (_timers[index]._running == false && _timers[index]._runCount < runTime)
	{
		_timers[index]._startMillis = millis();
		_timers[index]._running = true;
		_timers[index]._runCount++;
		_timers[index]._timeDelay = timeDelay;
	}
	return finished(index);
}

boolean Delay2::once(int index, unsigned long timeDelay)
{
	return start(index, timeDelay, 1);
}

boolean Delay2::finished(int index)
{
	if (millis() >= (_timers[index]._startMillis + _timers[index]._timeDelay) && _timers[index]._running == true)
	{
		_timers[index]._running = false;
		return true;
	}
	else
	{
		return false;
	}
}

void Delay2::reset(int index)
{
	_timers[index]._running = false;
	_timers[index]._runCount = 0;
}

int Delay2::runCount(int index)
{
	return _timers[index]._runCount;
}

unsigned long Delay2::time(int index)
{
	if (_timers[index]._running == true){
		return millis() - _timers[index]._startMillis;
	}
	else
	{
		return 0;
	}
}