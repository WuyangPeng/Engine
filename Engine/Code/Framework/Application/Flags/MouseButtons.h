// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:46)

#ifndef FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
#define FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H

#include "Framework/FrameworkDll.h"

#include "System/OpenGL/Flags/GlutKeyCodesFlags.h"

namespace Framework
{
	struct WindowMouseButtons
	{
		static constexpr auto sm_MouseLeftButton = 0;
		static constexpr auto sm_MouseMiddleButton = 1;
		static constexpr auto sm_MouseRightButton = 2;
	};

	struct GlutMouseButtons
	{
		static constexpr auto sm_MouseLeftButton = System::EnumCastUnderlying(System::GlutModifiersCodes::LeftButton);
		static constexpr auto sm_MouseMiddleButton = System::EnumCastUnderlying(System::GlutModifiersCodes::MiddleButton);
		static constexpr auto sm_MouseRightButton = System::EnumCastUnderlying(System::GlutModifiersCodes::RightButton);
	}; 

	struct AndroidMouseButtons
	{
		static constexpr auto sm_MouseLeftButton = 0;
		static constexpr auto sm_MouseMiddleButton = 1;
		static constexpr auto sm_MouseRightButton = 2;
	};

	struct LinuxMouseButtons
	{
		static constexpr auto sm_MouseLeftButton = 0;
		static constexpr auto sm_MouseMiddleButton = 1;
		static constexpr auto sm_MouseRightButton = 2;
	};

	struct MacintoshMouseButtons
	{
		static constexpr auto sm_MouseLeftButton = 0;
		static constexpr auto sm_MouseMiddleButton = 1;
		static constexpr auto sm_MouseRightButton = 2;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
