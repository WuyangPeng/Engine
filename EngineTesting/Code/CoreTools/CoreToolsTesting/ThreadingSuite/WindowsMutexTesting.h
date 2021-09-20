// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.0.2.3 (2020/03/05 11:55)

#ifndef CORE_TOOLS_THREADING_SUITE_WINDOWS_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_WINDOWS_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class WindowsMutexTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(WindowsMutexTesting);

	private:
		using Function = void (ClassType::*)();

	private:
		void MainTest();

		void RecursionTest();
		void MultithreadingLockingSuccessTest();
		void MultithreadingLockingFailureTest();

		// 递归测试
		void CreateRecursionTestHolder();

		// 多线程锁成功测试
		void CreateLockingSuccessThread();
		void CreateFourThread(Function function);
		void MultithreadingSuccessCallBack();
		void StaticValueTest();

		// 多线程锁失败测试
		void CreateLockingFailureThread();
		void MultithreadingFailureCallBack();
		void CreateFailureCallBackHolder();
		void TryLockFailureTest();

		void DoRunUnitTest() override;

	private:
		Mutex m_WindowsMutex1;
		DllMutex m_WindowsMutex2;
	};
}

#endif // CORE_TOOLS_THREADING_SUITE_WINDOWS_MUTEX_TESTING_H