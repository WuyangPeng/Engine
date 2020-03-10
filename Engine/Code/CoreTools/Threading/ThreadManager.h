// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/19 11:15)

#ifndef CORE_TOOLS_THREADING_THREAD_MANAGER_H
#define CORE_TOOLS_THREADING_THREAD_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(ThreadManagerImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE ThreadManager : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(ThreadManager);
		using ThreadSize = System::WindowSize;

	public:
		ThreadManager();

		CLASS_INVARIANT_DECLARE;

		void AddThread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

		void AddThreadUsePriority(void* function, void* userData, int priority, int processorNumber = 0, ThreadSize stackSize = 0);

		// ������ֹͣ�̡߳�
		void Resume();
		void Suspend();

		void Wait();

	private:
		IMPL_TYPE_DECLARE(ThreadManager);
	};
}

#endif // CORE_TOOLS_THREADING_THREAD_MANAGER_H
