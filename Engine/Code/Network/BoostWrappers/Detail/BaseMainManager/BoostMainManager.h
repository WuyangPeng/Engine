//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 16:25)

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
        BoostMainManager() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() override;

        [[nodiscard]] IOContextType& GetIOContext() noexcept override;
        void StopContext() override;
        [[nodiscard]] bool IsContextStop() const override;
        void RestartContext() override;

    protected:
        void DispatchStopContext();

    private:
        ExecutorWorkGuardContext m_ExecutorWorkGuardContext;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_MAIN_MANAGER_H
