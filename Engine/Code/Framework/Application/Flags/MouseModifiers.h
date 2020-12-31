// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
#define FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H

#include "Framework/FrameworkDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Window/Flags/WindowsKeyCodesFlags.h"
#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

namespace Framework
{
	struct WindowMouseModifiers
	{
		static const auto sm_ModifierControl = System::EnumCastUnderlying(System::WindowsModifiersCodes::Control);
		static const auto sm_ModifierLeftButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::LeftButton);
		static const auto sm_ModifierMiddleButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::MiddleButton);
		static const auto sm_ModifierRightButton = System::EnumCastUnderlying(System::WindowsModifiersCodes::RightButton);
		static const auto sm_ModifierShift = System::EnumCastUnderlying(System::WindowsModifiersCodes::Shift);
	};

	struct GlutMouseModifiers
	{
		static const auto sm_ModifierControl = System::EnumCastUnderlying(System::GlutModifiersCodes::Control);
		static const auto sm_ModifierLeftButton = System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
		static const auto sm_ModifierMiddleButton = System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
		static const auto sm_ModifierRightButton = System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
		static const auto sm_ModifierShift = System::EnumCastUnderlying(System::GlutModifiersCodes::Shift);
	};

	struct AndroidMouseModifiers
	{
		static const auto sm_ModifierControl = 0x0008;
		static const auto sm_ModifierLeftButton = 0x0001;
		static const auto sm_ModifierMiddleButton = 0x0010;
		static const auto sm_ModifierRightButton = 0x0002;
		static const auto sm_ModifierShift = 0x0004;
	};

	struct LinuxMouseModifiers
	{
		static constexpr auto sm_ModifierControl = 0;
		static constexpr auto sm_ModifierLeftButton = 0;
		static constexpr auto sm_ModifierMiddleButton = 0;
		static constexpr auto sm_ModifierRightButton = 0;
		static constexpr auto sm_ModifierShift = 0;
	};

	struct MacintoshMouseModifiers
	{
		static constexpr auto sm_ModifierControl = 0;
		static constexpr auto sm_ModifierLeftButton = 0;
		static constexpr auto sm_ModifierMiddleButton = 0;
		static constexpr auto sm_ModifierRightButton = 0;
		static constexpr auto sm_ModifierShift = 0;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
