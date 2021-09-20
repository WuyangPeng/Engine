// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.1 (2020/01/14 10:23)

#ifndef SYSTEM_THREADING_SUITE_THREAD_POOL_IO_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_POOL_IO_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/InitOnceUsing.h"
#include "System/Threading/Using/ThreadPoolUsing.h"
#include "System/Threading/Using/ProcessToolsUsing.h"
#include "System/Threading/Using/ConditionVariableUsing.h"
#include "System/MemoryTools/Using/HeapToolsUsing.h"
#include "System/MemoryTools/Using/VirtualToolsUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
	class ThreadPoolIoTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ThreadPoolIoTesting);

	private:
		void MainTest();
		void UsingThreadPoolTest();
		void ClosePoolIOTest();

		static void SYSTEM_WINAPI WorkCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, ThreadPoolWorkPtr work);

		static void SYSTEM_WINAPI TimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, ThreadPoolTimerPtr timer);

		static void SYSTEM_WINAPI Win32IOCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, WindowVoidPtr overlapped,
												  WindowULong ioResult, WindowPtrULong numberOfBytesTransferred, ThreadPoolIOPtr io);

		void DoRunUnitTest() override;
	};
}

#endif // SYSTEM_THREADING_SUITE_THREAD_POOL_IO_TESTING_H