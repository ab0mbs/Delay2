
#ifndef Delay2_h
#define Delay2_h

#include <Arduino.h>

class Delay2
{
	public:
		Delay2(uint8_t timerSize);
		boolean finished(uint8_t index);
		void reset(uint8_t index);
		boolean start(uint8_t index, unsigned long timeDelay);
		boolean start(uint8_t index, unsigned long timeDelay, int runTime);
		boolean once(uint8_t index, unsigned long timeDelay);
		int runCount(uint8_t index);
		unsigned long time(uint8_t index);
	private:
		typedef struct {
			unsigned long _timeDelay;
			unsigned long _startMillis;
			int _runCount;
			boolean _running;
		} TimeData;
		static const int _timerSize;
		TimeData *_timers;
};
#endif