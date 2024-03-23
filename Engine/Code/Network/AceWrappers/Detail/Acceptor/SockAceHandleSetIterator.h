/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:32)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/HandleSetIteratorImpl.h"

#ifdef NETWORK_USE_ACE

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAceHandleSetIterator final : public HandleSetIteratorImpl
    {
    public:
        using ClassType = SockAceHandleSetIterator;
        using ParentType = HandleSetIteratorImpl;

    public:
        explicit SockAceHandleSetIterator(const ACEHandleSet& handleSet);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD ACEHandle operator()() override;

    private:
        ACE_Handle_Set_Iterator aceHandleSetIter;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
