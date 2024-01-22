/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:08)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_BASE_MAIN_MANAGER_H

#include "Network/NetworkDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "Network/Interface/Detail/BaseMainManagerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NetworkMainManager final : public BaseMainManagerImpl
    {
    public:
        using ClassType = NetworkMainManager;
        using ParentType = BaseMainManagerImpl;

    public:
        explicit NetworkMainManager(CoreTools::DisableNotThrow disableNotThrow);
        ~NetworkMainManager() noexcept;

        NetworkMainManager(const NetworkMainManager& rhs) noexcept = default;
        NetworkMainManager& operator=(const NetworkMainManager& rhs) noexcept = default;
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
