//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:26)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H

#include "Network/NetworkDll.h"

#include "BoostMainManager.h"
#include "System/Helper/PragmaWarning/PtrVector.h"
#include "Network/Configuration/ConfigurationFwd.h"

#include <thread>
#include <vector>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostMainManagerUseThreads : public BoostMainManager
    {
    public:
        using ClassType = BoostMainManagerUseThreads;
        using ParentType = BoostMainManager;

    public:
        explicit BoostMainManagerUseThreads(const ConfigurationSubStrategy& subStrategy);
        ~BoostMainManagerUseThreads() noexcept;
        BoostMainManagerUseThreads(const BoostMainManagerUseThreads&) = default;
        BoostMainManagerUseThreads& operator=(const BoostMainManagerUseThreads&) = default;
        BoostMainManagerUseThreads(BoostMainManagerUseThreads&&) noexcept = default;
        BoostMainManagerUseThreads& operator=(BoostMainManagerUseThreads&&) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void StopContext() override;
        void RestartContext() override;
        void Run() noexcept override;

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

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H
