
#ifndef Delay2_h
#define Delay2_h

#include <Arduino.h>

class Delay2
{
	public:
		Delay2();
		boolean finished(int index);
		void reset(int index);
		boolean start(int index, unsigned long timeDelay);
		boolean start(int index, unsigned long timeDelay, int runTime);
		boolean once(int index, unsigned long timeDelay);
		int runCount(int index);
		unsigned long time(int index);
	private:
		typedef struct {
			unsigned long _timeDelay;
			unsigned long _startMillis;
			int _runCount;
			boolean _running;
		} TimeData;
		TimeData _timers[32];
};
#endif