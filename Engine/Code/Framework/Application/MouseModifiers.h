// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:09)

#ifndef FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
#define FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H

#include "Framework/FrameworkDll.h"

namespace Framework
{
	struct FRAMEWORK_DEFAULT_DECLARE WindowMouseModifiers
	{
		static const int sm_ModifierControl;
		static const int sm_ModifierLeftButton;
		static const int sm_ModifierMiddleButton;
		static const int sm_ModifierRightButton;
		static const int sm_ModifierShift;
	};

	struct FRAMEWORK_DEFAULT_DECLARE GlutMouseModifiers
	{
		static const int sm_ModifierControl;
		static const int sm_ModifierLeftButton;
		static const int sm_ModifierMiddleButton;
		static const int sm_ModifierRightButton;
		static const int sm_ModifierShift;
	};

	struct FRAMEWORK_DEFAULT_DECLARE AndroidMouseModifiers
	{
		static const int sm_ModifierControl;
		static const int sm_ModifierLeftButton;
		static const int sm_ModifierMiddleButton;
		static const int sm_ModifierRightButton;
		static const int sm_ModifierShift;
	};
}

#endif // FRAMEWORK_APPLICATION_MOUSE_MODIFIERS_H
