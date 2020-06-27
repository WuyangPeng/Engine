// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 10:50)

#ifndef FRAMEWORK_WINDOW_PROCESS_FWD_H
#define FRAMEWORK_WINDOW_PROCESS_FWD_H

namespace Framework
{
	enum class MouseButtonsTypes;
	enum class MouseStateTypes;

	class VirtualKeysTypes;
	class WindowMessageLoop;
	class WindowMessageInterface;

	template <typename MiddleLayer>
	class WindowMessage;

	class WindowProcessManager;

	template <typename WindowMessage>
	class WindowProcessHandle;

	class WindowMessageUnitTestSuite;
}

#endif // FRAMEWORK_WINDOW_PROCESS_FWD_H