// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
#define FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
	struct FRAMEWORK_DEFAULT_DECLARE WindowMouseButtons
	{
		static const int sm_MouseLeftButton;
		static const int sm_MouseMiddleButton;
		static const int sm_MouseRightButton;
	};

	struct FRAMEWORK_DEFAULT_DECLARE GlutMouseButtons
	{
		static const int sm_MouseLeftButton;
		static const int sm_MouseMiddleButton;
		static const int sm_MouseRightButton;
	};

	struct FRAMEWORK_DEFAULT_DECLARE AndroidMouseButtons
	{
		static const int sm_MouseLeftButton;
		static const int sm_MouseMiddleButton;
		static const int sm_MouseRightButton;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_BUTTONS_H
