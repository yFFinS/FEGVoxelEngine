#pragma once

namespace feg {
	class Time
	{
	public:
		static void Tick();

	private:
		static double _totalTime;
		static double _lastTickTime;
		static double _deltaTime;
		static double _updateFrequency;
	public:
		static float getDeltaTime();
	};
}