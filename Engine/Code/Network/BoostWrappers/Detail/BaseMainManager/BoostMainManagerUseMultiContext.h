//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:26)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContextThread.h"
#include "System/Helper/PragmaWarning/PtrVector.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostMainManagerUseMultiContext : public BaseMainManagerImpl
    {
    public:
        using ClassType = BoostMainManagerUseMultiContext;
        using ParentType = BaseMainManagerImpl;

    public:
        explicit BoostMainManagerUseMultiContext(const ConfigurationSubStrategy& subStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() noexcept override;

        [[nodiscard]] IOContextType& GetIOContext() override;
        void StopContext() override;
        [[nodiscard]] bool IsContextStop() const override;
        void RestartContext() override;

    private:
        using Container = boost::ptr_vector<ExecutorWorkGuardContextThread>;

    private:
        void InitContainer(int containerNumber);

    private:
        Container m_Container;
        int m_CurrentIndex;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
