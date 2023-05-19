///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 10:56)

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

        NODISCARD virtual ACEHandleType operator()();
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_ITERATOR_IMPL_H
