// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:43)

#ifndef FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
#define FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H

#include "Framework/FrameworkDll.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"
#include "System/Android/Flags/AndroidKeyCodesFlags.h"

namespace Framework
{
	struct WindowKeyboardModifiers
	{
		static constexpr auto sm_KeyShift = System::EnumCastUnderlying(System::WindowsKeyCodes::Shift);
		static constexpr auto sm_KeyControl = System::EnumCastUnderlying(System::WindowsKeyCodes::Control);
		static constexpr auto sm_KeyAlt = System::EnumCastUnderlying(System::WindowsKeyCodes::Menu);
	};

	struct GlutKeyboardModifiers
	{
		static constexpr auto sm_KeyShift = System::EnumCastUnderlying(System::GlutModifiersCodes::Shift);
		static constexpr auto sm_KeyControl = System::EnumCastUnderlying(System::GlutModifiersCodes::Control);
		static constexpr auto sm_KeyAlt = System::EnumCastUnderlying(System::GlutModifiersCodes::Alt);
	};

	struct AndroidKeyboardModifiers
	{
		static constexpr auto sm_KeyShift = 0;
		static constexpr auto sm_KeyControl = 0;
		static constexpr auto sm_KeyAlt = 0;
	};

	struct LinuxKeyboardModifiers
	{
		static constexpr auto sm_KeyShift = 0;
		static constexpr auto sm_KeyControl = 0;
		static constexpr auto sm_KeyAlt = 0;
	};

	struct MacintoshKeyboardModifiers
	{
		static constexpr auto sm_KeyShift = 0;
		static constexpr auto sm_KeyControl = 0;
		static constexpr auto sm_KeyAlt = 0;
	};
}

#endif // FRAMEWORK_APPLICATION_KEYBOARD_MODIFIERS_H
