// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:24)

#ifndef FRAMEWORK_ANDROID_FRAME_FWD_H
#define FRAMEWORK_ANDROID_FRAME_FWD_H

namespace Framework
{
	class AndroidProcessManager;
	class AndroidCallBackInterface;
	class AndroidMessageLoop;
	class AndroidCallBackUnitTestSuite;

	template <typename AndroidCallBack>
	class AndroidProcess;

	template <typename ModelViewControllerMiddleLayerContainer>
	class AndroidCallBack;

	template <typename AndroidProcess>
	class AndroidFrameBuild;
}

#endif // FRAMEWORK_ANDROID_FRAME_FWD_H