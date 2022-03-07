///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 14:16)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetIteratorImpl
    {
    public:
        using ClassType = HandleSetIteratorImpl;
        using FactoryType = HandleSetIteratorFactory;

    public:
        HandleSetIteratorImpl() noexcept = default;
        virtual ~HandleSetIteratorImpl() noexcept = default;
        HandleSetIteratorImpl(const HandleSetIteratorImpl& rhs) = default;
        HandleSetIteratorImpl& operator=(const HandleSetIteratorImpl& rhs) = default;
        HandleSetIteratorImpl(HandleSetIteratorImpl&& rhs) noexcept = default;
        HandleSetIteratorImpl& operator=(HandleSetIteratorImpl&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual ACEHandle operator()();
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
