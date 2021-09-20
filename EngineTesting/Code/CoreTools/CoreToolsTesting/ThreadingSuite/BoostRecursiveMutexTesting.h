// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.3 (2020/03/05 11:50)

#ifndef CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class BoostRecursiveMutexTesting : public UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BoostRecursiveMutexTesting);

	private:
		using Function = void (ClassType::*)();

	private:
		void MainTest();

		void RecursionTest();
		void MultithreadingLockingSuccessTest();
		void MultithreadingLockingFailureTest();

		// �ݹ����
		void CreateRecursionTestHolder();

		// ���߳����ɹ�����
		void CreateLockingSuccessThread();
		void CreateFourThread(Function function);
		void MultithreadingSuccessCallBack();
		void StaticValueTest();	

		// ���߳���ʧ�ܲ���
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

#endif // CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H