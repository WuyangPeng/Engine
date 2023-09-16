///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 11:28)

#ifndef NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
#define NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BaseMainManagerImpl
    {
    public:
        using ClassType = BaseMainManagerImpl;
        using FactoryType = BaseMainManagerFactory;

    public:
        BaseMainManagerImpl() noexcept;
        virtual ~BaseMainManagerImpl() noexcept = default;
        BaseMainManagerImpl(const BaseMainManagerImpl& rhs) noexcept = default;
        BaseMainManagerImpl& operator=(const BaseMainManagerImpl& rhs) noexcept = default;
        BaseMainManagerImpl(BaseMainManagerImpl&& rhs) noexcept = default;
        BaseMainManagerImpl& operator=(BaseMainManagerImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual void Run() = 0;

        // 非boost主管理类默认抛出异常。
        NODISCARD virtual IoContextType& GetContext();
        virtual void StopContext();
        NODISCARD virtual bool IsContextStop() const;
        virtual void RestartContext();
    };
}

#endif  // NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
