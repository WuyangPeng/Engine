///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 14:23)

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

        void Run() noexcept final;

        void StopContext() noexcept final;
        NODISCARD bool IsContextStop() const noexcept final;
        void RestartContext() noexcept final;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_MAIN_MANAGER_H
