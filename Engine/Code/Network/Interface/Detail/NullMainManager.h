///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/08 17:27)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
#define NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullMainManager final : public BaseMainManagerImpl
    {
    public:
        using ClassType = NullMainManager;
        using ParentType = BaseMainManagerImpl;

    public:
        NullMainManager() noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void Run() noexcept override;

        void StopContext() noexcept override;
        NODISCARD bool IsContextStop() const noexcept override;
        void RestartContext() noexcept override;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
