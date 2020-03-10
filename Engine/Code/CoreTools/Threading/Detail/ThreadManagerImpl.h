// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:13)

#ifndef CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ThreadImpl.h"

#include <vector>
#include <memory>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ThreadManagerImpl
	{
	public:
		using ClassType = ThreadManagerImpl;
		using ThreadSize = System::WindowSize;
		using ThreadHandle = System::ThreadHandle;		

	public:
		ThreadManagerImpl();

		CLASS_INVARIANT_DECLARE;

		void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

		void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

		// 启动和停止线程。
		void Resume();
		void Suspend();

		void Wait();

	private:
		using ThreadImplPtr = std::shared_ptr<ThreadImpl>;
		using ThreadContainer = std::vector<ThreadImplPtr>;
		using ThreadHandleContainer = std::vector<ThreadHandle>;

	private:
		ThreadContainer m_Thread;
		ThreadHandleContainer m_ThreadHandle;
	};
}

#endif // CORE_TOOLS_THREADING_THREAD_MANAGER_IMPL_H
