// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 13:42)

#ifndef FRAMEWORK_APPLICATION_FWD_H
#define FRAMEWORK_APPLICATION_FWD_H

namespace Framework
{
	enum class PlatformTypes;

	struct WindowKeyIdentifiers;
	struct GlutKeyIdentifiers;
	struct AndroidKeyIdentifiers;
	struct LinuxKeyIdentifiers;
	struct MacintoshKeyIdentifiers;

	struct WindowKeyboardModifiers;
	struct GlutKeyboardModifiers;
	struct AndroidKeyboardModifiers;
	struct LinuxKeyboardModifiers;
	struct MacintoshKeyboardModifiers;

	struct WindowMouseButtons;
	struct GlutMouseButtons;
	struct AndroidMouseButtons;
	struct LinuxMouseButtons;
	struct MacintoshMouseButtons;

	struct WindowMouseState;
	struct GlutMouseState;
	struct AndroidMouseState;
	struct LinuxMouseState;
	struct MacintoshMouseState;

	struct WindowMouseModifiers;
	struct GlutMouseModifiers;
	struct AndroidMouseModifiers;
	struct LinuxMouseModifiers;
	struct MacintoshMouseModifiers;

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