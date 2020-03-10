// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:05)

#ifndef FRAMEWORK_APPLICATION_FWD_H
#define FRAMEWORK_APPLICATION_FWD_H

#include "ApplicationTrait.h"

namespace Framework
{
	struct WindowKeyIdentifiers;
	struct GlutKeyIdentifiers;
	struct AndroidKeyIdentifiers;
	struct WindowKeyboardModifiers;
	struct GlutKeyboardModifiers;
	struct AndroidKeyboardModifiers;
	struct WindowMouseButtons;
	struct GlutMouseButtons;
	struct AndroidMouseButtons;
	struct WindowMouseState;
	struct GlutMouseState;
	struct AndroidMouseState;
	struct WindowMouseModifiers;
	struct GlutMouseModifiers;
	struct AndroidMouseModifiers;

	template <PlatformTypes types>
	struct ApplicationTrait;

	class FontInformation;
	class MousePosition;
	class PerformanceMeasurements;
	class WindowApplicationInformation;
	class GLUTApplicationInformation;

	class PixelScreen;
	class CameraMotion;
	class ObjectMotion;
}

#endif // FRAMEWORK_APPLICATION_FWD_H