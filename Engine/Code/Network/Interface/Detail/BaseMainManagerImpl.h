//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 16:26)

#ifndef NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
#define NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class BaseMainManagerFactory;
    class NETWORK_HIDDEN_DECLARE BaseMainManagerImpl
    {
    public:
        using ClassType = BaseMainManagerImpl;
        using FactoryType =BaseMainManagerFactory;

    public:
        BaseMainManagerImpl() noexcept;
        virtual ~BaseMainManagerImpl() noexcept = default;
        BaseMainManagerImpl(const BaseMainManagerImpl& rhs) = default;
        BaseMainManagerImpl& operator=(const BaseMainManagerImpl& rhs) = default;
        BaseMainManagerImpl(BaseMainManagerImpl&& rhs) noexcept = default;
        BaseMainManagerImpl& operator=(BaseMainManagerImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

    public:
        virtual void Run() = 0;

        // ��boost��������Ĭ���׳��쳣��
        [[nodiscard]] virtual IOContextType& GetIOContext();
        virtual void StopContext();
        [[nodiscard]] virtual bool IsContextStop() const;
        virtual void RestartContext();
    };
}

#endif  // NETWORK_INTERFACE_BASE_MAIN_MANAGER_IMPL_H
