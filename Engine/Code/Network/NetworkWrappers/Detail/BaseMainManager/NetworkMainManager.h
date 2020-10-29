//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 18:54)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkMainManager : public BaseMainManagerImpl
    {
    public:
        using ClassType = NetworkMainManager;
        using ParentType = BaseMainManagerImpl;

    public:
        NetworkMainManager();
        ~NetworkMainManager() noexcept;

        NetworkMainManager(const NetworkMainManager& rhs) = default;
        NetworkMainManager& operator=(const NetworkMainManager& rhs) = default;
        NetworkMainManager(NetworkMainManager&& rhs) noexcept = default;
        NetworkMainManager& operator=(NetworkMainManager&& rhs) noexcept = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    public:
        void Run() noexcept override;

    private:
        void Init();
        void Release() noexcept;
    };
}

#endif  // NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
