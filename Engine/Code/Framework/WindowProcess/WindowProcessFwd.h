// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.4 (2019/08/01 10:01)

#ifndef FRAMEWORK_WINDOW_PROCESS_FWD_H
#define FRAMEWORK_WINDOW_PROCESS_FWD_H

namespace Framework
{
	class WindowMessageLoop;
	class WindowMessageInterface;
	class WindowProcessManager;	
	class MiddleLayerInterface;
	class VirtualKeysTypes;
	class WindowMessageUnitTestSuite;

	template <typename WindowMessage>
	class WindowProcessHandle;

	template <typename ModelViewControllerMiddleLayerContainer>
	class WindowMessage;
}

#endif // FRAMEWORK_WINDOW_PROCESS_FWD_H