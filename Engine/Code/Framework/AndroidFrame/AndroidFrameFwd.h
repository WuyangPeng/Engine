// Copyright (c) 2010-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.3.0.1 (2020/05/21 16:40)

#ifndef FRAMEWORK_ANDROID_FRAME_FWD_H
#define FRAMEWORK_ANDROID_FRAME_FWD_H

namespace Framework
{
	class AndroidProcessManager;

	template <typename AndroidCallBack>
	class AndroidProcess;

	class AndroidCallBackInterface;

	template <typename MiddleLayer>
	class AndroidCallBack;

	class AndroidCallBackUnitTestSuite;
	class AndroidMessageLoop;	

	template <typename AndroidProcess>
	class AndroidFrameBuild;
}

#endif // FRAMEWORK_ANDROID_FRAME_FWD_H