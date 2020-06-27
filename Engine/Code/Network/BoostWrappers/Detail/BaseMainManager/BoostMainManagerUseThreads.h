// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:45)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H

#include "Network/NetworkDll.h"

#include "BoostMainManager.h"
#include "Network/Configuration/ConfigurationFwd.h"

#include "System/Helper/PragmaWarning/PtrVector.h"
#include <vector>
#include <thread>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostMainManagerUseThreads : public BoostMainManager
	{
	public:
		using ClassType = BoostMainManagerUseThreads;
		using ParentType = BoostMainManager;

	public:
		explicit BoostMainManagerUseThreads(const ConfigurationSubStrategy& subStrategy);
		virtual ~BoostMainManagerUseThreads();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual void StopContext() override;
		virtual void RestartContext() override;
		virtual void Run() override;

	private:
		void InitThread();
		void DoInitThread();
		void JoinThreads();
		void DoJoinThreads();
		void ThreadsRun();

	private:
		using ThreadType = std::thread;
		using Container = boost::ptr_vector<ThreadType>;

	private:
		Container m_Thread;
		int m_ThreadNumber;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H
