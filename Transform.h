#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "Vector3.h"
#include "Component.h"
#include <set>

namespace feg {
	class Transform :
		public Component
	{
	public:
		void Translate(const Vector3& direction);
	public:
		void setPosition(const Vector3& position);
		Vector3 getPosition() const noexcept;
		void setScale(const Vector3& scale);
		Vector3 getScale() const noexcept;

	private:
		Vector3 _localPosition;
		Vector3 _position;
		Vector3 _scale;
		Transform* _parent;
		std::set<Transform*> _childs;
	};
}

#endif // !TRANSFORM_H