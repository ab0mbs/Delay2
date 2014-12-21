#include <Arduino.h>
#include <Delay2.h>

Delay2::Delay2(uint8_t timerSize)
{
	// Define variables
	static const uint8_t _timerSize = timerSize;
	/*  Here for reference
	typedef struct {
		unsigned long _timeDelay;
		unsigned long _startMillis;
		int _runCount;
		boolean _running;
	} TimeData;
	*/

	// Create timers array
	_timers = (TimeData *)malloc(sizeof(TimeData) * _timerSize);

	// Initialize values in _timers
	for (uint8_t i = 0; i < _timerSize; i++)
	{
		_timers[i]._runCount = 0;
		_timers[i]._running = false;
	}
}
boolean Delay2::start(uint8_t index, unsigned long timeDelay)
{
	if (_timers[index]._running == false)
	{
		_timers[index]._startMillis = millis();
		_timers[index]._running = true;
		_timers[index]._timeDelay = timeDelay;
	}
	return finished(index);
}
boolean Delay2::start(uint8_t index, unsigned long timeDelay, int runTime)
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

boolean Delay2::once(uint8_t index, unsigned long timeDelay)
{
	return start(index, timeDelay, 1);
}

boolean Delay2::finished(uint8_t index)
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

void Delay2::reset(uint8_t index)
{
	_timers[index]._running = false;
	_timers[index]._runCount = 0;
}

int Delay2::runCount(uint8_t index)
{
	return _timers[index]._runCount;
}

unsigned long Delay2::time(uint8_t index)
{
	if (_timers[index]._running == true){
		return millis() - _timers[index]._startMillis;
	}
	else
	{
		return 0;
	}
}