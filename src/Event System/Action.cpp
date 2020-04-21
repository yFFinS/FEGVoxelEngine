
namespace feg {
	unsigned int Action::_currentId = 0;

	Action::Action(const std::function<void()>& action) noexcept
	{
		_id = _currentId++;
		_handle = action;
	}

	Action::~Action() noexcept
	{
	}

	void Action::Invoke() const
	{
		_handle();
	}

	bool operator<(const Action& lhs, const Action& rhs) noexcept
	{
		return lhs._id < rhs._id;
	}

}
