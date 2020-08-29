// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:45)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_USE_MULTI_CONTEX_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContextThread.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

#include "System/Helper/PragmaWarning/PtrVector.h"

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

        IOContextType& GetIOContext() override;
        void StopContext() override;
        bool IsContextStop() const override;
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
