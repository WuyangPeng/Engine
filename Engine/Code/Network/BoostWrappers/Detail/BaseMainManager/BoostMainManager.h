///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 14:22)

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
