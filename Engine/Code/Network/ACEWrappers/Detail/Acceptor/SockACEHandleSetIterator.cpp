//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 15:00)

#include "Network/NetworkExport.h"

#include "SockACEHandleSetIterator.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::SockACEHandleSetIterator::SockACEHandleSetIterator(const ACEHandleSet& handleSet)
    : ParentType{}, m_ACEHandleSetIter{ handleSet }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSetIterator)

Network::ACEHandle Network::SockACEHandleSetIterator::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    return m_ACEHandleSetIter();
}

#endif  // NETWORK_USE_ACE