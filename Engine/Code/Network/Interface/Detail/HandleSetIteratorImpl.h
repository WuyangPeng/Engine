//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 20:04)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetIteratorImpl
    {
    public:
        using ClassType = HandleSetIteratorImpl;

    public:
        HandleSetIteratorImpl() noexcept = default;
        virtual ~HandleSetIteratorImpl() noexcept = default;
        HandleSetIteratorImpl(const HandleSetIteratorImpl&) = default;
        HandleSetIteratorImpl& operator=(const HandleSetIteratorImpl&) = default;
        HandleSetIteratorImpl(HandleSetIteratorImpl&&) noexcept = default;
        HandleSetIteratorImpl& operator=(HandleSetIteratorImpl&&) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] virtual ACEHandle operator()();
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
