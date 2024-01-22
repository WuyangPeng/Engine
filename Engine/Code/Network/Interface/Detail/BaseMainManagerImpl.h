/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:16)

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

        // ��boost��������Ĭ���׳��쳣��
        NODISCARD virtual IoContextType& GetContext();
        virtual void StopContext();
        NODISCARD virtual bool IsContextStop() const;
        virtual void RestartContext();
    };
}

#endif  // NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
