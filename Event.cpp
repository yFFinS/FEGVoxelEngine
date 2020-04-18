#include "Event.h"

namespace feg {
	Event::~Event() noexcept
	{
		_actions.clear();
	}

	Event::Event() noexcept : _actions()
	{
	}

	void Event::Subscribe(Action& callback) noexcept
	{
		_actions.insert(&callback);
	}

	void Event::Unsubscribe(Action& callback) noexcept
	{
		if (_actions.find(&callback) != _actions.end())
			_actions.erase(&callback);
	}

	void Event::Invoke() const
	{
		for (auto handle : _actions)
		{
			handle->Invoke();
		}
	}

	void Event::operator()(const Event& evt) const
	{
		evt.Invoke();
	}
	void operator+=(Event& evt, Action& callback) noexcept
	{
		evt.Subscribe(callback);
	}
	void operator-=(Event& evt, Action& callback) noexcept
	{
		evt.Unsubscribe(callback);
	}
}

