//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 14:31)

#ifndef NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
#define NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

    #include "Network/Interface/Detail/HandleSetIteratorImpl.h"

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

        [[nodiscard]] ACEHandle operator()() override;

    private:
        ACE_Handle_Set_Iterator m_ACEHandleSetIter;
    };
}

#endif  // NETWORK_USE_ACE

#endif  // NETWORK_NETWORK_INTERFACE_ACE_HANDLE_SET_ITERATOR_H
