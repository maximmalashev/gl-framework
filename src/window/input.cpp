#include "pch.h"
#include "input.h"

namespace gl
{
	bool Input::m_keys[512];
	bool Input::m_keysReleased[512];
	bool Input::m_keysPressed[512];

	bool Input::KeyPressed(const KeyCode code)
	{
		return m_keysPressed[static_cast<u32>(code)];
	}

	bool Input::KeyReleased(const KeyCode code)
	{
		return m_keysReleased[static_cast<u32>(code)];
	}

	bool Input::Key(const KeyCode code)
	{
		return m_keys[static_cast<u32>(code)];
	}
	void Input::ResetPressed()
	{
		for (bool& key : m_keysPressed)
			key = false;
	}

	void Input::ResetReleased()
	{
		for (bool& key : m_keysReleased)
			key = false;
	}
}


