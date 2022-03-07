///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 19:15)

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
        Container threads;
        int threadNumber;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_THREADS_H
