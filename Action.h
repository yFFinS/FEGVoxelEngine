#pragma once
#ifndef ACTION_H
#define ACTION_H
#include <functional>
namespace feg {

	class Action
	{
	public:
		Action(const std::function<void()>& action) noexcept;
		~Action() noexcept;
		void Invoke() const;
		friend bool operator<(const Action& lhs, const Action& rhs) noexcept;

	private:
		std::function<void()> _handle;
		unsigned int _id;
		static unsigned int _currentId;
	};

}
#endif // !ACTION_H

