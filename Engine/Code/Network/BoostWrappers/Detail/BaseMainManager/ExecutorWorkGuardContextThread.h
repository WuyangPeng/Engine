// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/21 13:08)


#ifndef NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
#define NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H

#include "Network/NetworkDll.h" 

#include "ExecutorWorkGuardContext.h"

#include <boost/noncopyable.hpp> 
#include <thread>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ExecutorWorkGuardContextThread : private boost::noncopyable
	{
	public:
		using ClassType = ExecutorWorkGuardContextThread;

	public:
		ExecutorWorkGuardContextThread();
		~ExecutorWorkGuardContextThread();

		CLASS_INVARIANT_DECLARE;

	public:
		IOContextType& GetIOContext();
		void StopContext();
		bool IsContextStop() const;
		void RestartContext();

	private:
		using ThreadType = std::thread;
		using ThreadTypePtr = std::unique_ptr<ThreadType>;

	private:
		void InitThread();
		void JoinThreads();

	private:
		ExecutorWorkGuardContext m_ExecutorWorkGuardContext;
		ThreadTypePtr m_Thread;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_EXECUTOR_WORK_GUARD_CONTEXT_THREAD_H
