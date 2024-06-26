/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:23)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "ExecutorWorkGuardContext.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostMainManager : public BaseMainManagerImpl
    {
    public:
        using ClassType = BoostMainManager;
        using ParentType = BaseMainManagerImpl;

    public:
        explicit BoostMainManager(CoreTools::DisableNotThrow disableNotThrow);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() override;

        NODISCARD IoContextType& GetContext() noexcept override;
        void StopContext() override;
        NODISCARD bool IsContextStop() const override;
        void RestartContext() override;

    protected:
        void DispatchStopContext();

    private:
        ExecutorWorkGuardContext executorWorkGuardContext;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H
