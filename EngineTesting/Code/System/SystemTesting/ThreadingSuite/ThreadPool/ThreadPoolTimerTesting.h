// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.1 (2020/01/14 10:23)

#ifndef SYSTEM_THREADING_SUITE_THREAD_POOL_TIMER_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_POOL_TIMER_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/InitOnceUsing.h"
#include "System/Threading/Using/ThreadPoolUsing.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace System
{
	class ThreadPoolTimerTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ThreadPoolTimerTesting);

	private:
		void MainTest();
		void UsingThreadPoolTest();

		static void SYSTEM_WINAPI WorkCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, ThreadPoolWorkPtr work);

		static void SYSTEM_WINAPI TimerCallback(ThreadPoolCallBackInstancePtr instance, WindowVoidPtr context, ThreadPoolTimerPtr timer);

		void DoRunUnitTest() override;
	};
}

#endif // SYSTEM_THREADING_SUITE_THREAD_POOL_TIMER_TESTING_H