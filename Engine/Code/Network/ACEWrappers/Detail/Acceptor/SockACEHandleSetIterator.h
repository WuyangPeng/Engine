///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/22 13:46)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/HandleSetIteratorImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockACEHandleSetIterator : public HandleSetIteratorImpl
    {
    public:
        using ClassType = SockACEHandleSetIterator;
        using ParentType = HandleSetIteratorImpl;

    public:
        explicit SockACEHandleSetIterator(const ACEHandleSet& handleSet);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ACEHandle operator()() override;

    private:
        ACE_Handle_Set_Iterator aceHandleSetIter;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
