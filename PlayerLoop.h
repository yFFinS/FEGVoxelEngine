#pragma once
#ifndef PLAYER_LOOP_H
#define PLAYER_LOOP_H
#include "SceneObject.h"

namespace feg {
	class PlayerLoop
	{
	public:
		void Initialize();
	private:
		void Update();
		void PreRender();
		void PostRender();
	};
}



#endif // !PLAYER_LOOP_H
