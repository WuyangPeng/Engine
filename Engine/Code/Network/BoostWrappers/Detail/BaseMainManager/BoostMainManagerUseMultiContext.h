///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 19:13)

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

        NODISCARD IOContextType& GetIOContext() override;
        void StopContext() override;
        NODISCARD bool IsContextStop() const override;
        void RestartContext() override;

    private:
        using Container = boost::ptr_vector<ExecutorWorkGuardContextThread>;

    private:
        void InitContainer(int containerNumber);

    private:
        Container container;
        int currentIndex;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
