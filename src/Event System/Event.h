#pragma once
#ifndef EVENT_H
#define EVENT_H

namespace feg {
	class Event
	{
	public:
		~Event() noexcept;
		Event() noexcept;
		void Subscribe(Action& callback) noexcept;
		void Unsubscribe(Action& callback) noexcept;
		void Invoke() const;
		void operator()(const Event& evt) const;
		friend void operator+=(Event& evt, Action& callback) noexcept;
		friend void operator-=(Event& evt, Action& callback) noexcept;

	private:
		std::set<Action*> _actions;
	};

}
#endif // !EVENT_H
