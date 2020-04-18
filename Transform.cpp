#include "Transform.h"

namespace feg {
	void Transform::Translate(const Vector3& direction)
	{
		setPosition(_position + direction);
	}

	void Transform::setPosition(const Vector3& position)
	{
		_position = position + _localPosition;
		for (auto& child : _childs)
		{
			child->setPosition(_position);
		}
	}
	Vector3 Transform::getPosition() const noexcept
	{
		return _position;
	}
	void Transform::setScale(const Vector3& scale)
	{
		_scale = scale;
	}
	Vector3 Transform::getScale() const noexcept
	{
		return _scale;
	}
}