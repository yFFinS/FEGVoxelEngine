#ifndef TIME_H
#define TIME_H

#include "Time.h"
#include <time.h>

namespace feg {
	double Time::_totalTime = 0;
	double Time::_deltaTime = 0;
	double Time::_lastTickTime = 0;
	double Time::_updateFrequency = (double)1 / CLOCKS_PER_SEC;

	void Time::Tick() {
		double time = clock();
		_deltaTime = (time - _lastTickTime) * _updateFrequency;
		_lastTickTime = time;
		_totalTime += time;
	}

	float Time::getDeltaTime() {
		return static_cast<float>(_deltaTime);
	}
}


#endif // !TIME_H