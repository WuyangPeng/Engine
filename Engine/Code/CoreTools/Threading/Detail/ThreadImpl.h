// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/19 11:12)

#ifndef CORE_TOOLS_THREADING_THREAD_IMPL_H
#define CORE_TOOLS_THREADING_THREAD_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Window/Using/WindowUsing.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "System/Threading/Using/CriticalSectionUsing.h"

#include <boost/noncopyable.hpp>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ThreadImpl : private boost::noncopyable
	{
	public:
		using ClassType = ThreadImpl;
		using ThreadSize = System::WindowSize;
		using ThreadHandle = System::ThreadHandle;
		using ThreadingDWord = System::WindowDWord;

	public:
		ThreadImpl(void* function, void* userData, int processorNumber = 0, ThreadSize stackSize = 0);
		~ThreadImpl();
		ThreadImpl(const ThreadImpl&) = delete;
		ThreadImpl& operator=(const ThreadImpl&) = delete;
		ThreadImpl(ThreadImpl&&) noexcept = delete;
		ThreadImpl& operator=(ThreadImpl&&) noexcept = delete;

		CLASS_INVARIANT_DECLARE;

		ThreadingDWord GetThreadID() const noexcept;
		ThreadHandle GetThreadHandle() noexcept;

		// 启动和停止线程。
		void Resume();
		void Suspend();

		void Wait();

		void SetThreadPriority(int priority);
		int GetThreadPriority() const;

	private:
		static constexpr ThreadingDWord sm_FailResult{ static_cast<ThreadingDWord>(-1) };

	private:
		ThreadingDWord m_ThreadID;
		void* m_Function;
		void* m_UserData;
		int m_ProcessorNumber;
		ThreadSize m_StackSize;
		ThreadHandle m_Thread;
	};
}

#endif // CORE_TOOLS_THREADING_THREAD_IMPL_H
