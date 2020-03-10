// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:14)

#ifndef CORE_TOOLS_THREADING_THREAD_H
#define CORE_TOOLS_THREADING_THREAD_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>

CORE_TOOLS_EXPORT_SHARED_PTR(ThreadImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE Thread : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(Thread);
		using ThreadSize = System::WindowSize;

	public:
		Thread(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);

		CLASS_INVARIANT_DECLARE;

		// 启动和停止线程。
		void Resume();
		void Suspend();

		void Wait();

		void SetThreadPriority(int priority);
		int GetThreadPriority() const;

	private:
		IMPL_TYPE_DECLARE(Thread);
	};
}

#endif // CORE_TOOLS_THREADING_THREAD_H