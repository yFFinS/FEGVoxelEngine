#include "Action.h"

unsigned int feg::Action::_currentId = 0;

feg::Action::Action(const std::function<void()>& action) noexcept
{
	_id = _currentId++;
	_handle = action;
}

feg::Action::~Action() noexcept
{
}

void feg::Action::Invoke() const
{
	_handle();
}

bool feg::operator<(const Action& lhs, const Action& rhs) noexcept
{
	return lhs._id < rhs._id;
}
