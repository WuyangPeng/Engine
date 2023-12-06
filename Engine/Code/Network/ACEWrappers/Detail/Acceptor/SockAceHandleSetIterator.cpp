///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 15:46)

#include "Network/NetworkExport.h"

#include "SockAceHandleSetIterator.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::SockAceHandleSetIterator::SockAceHandleSetIterator(const ACEHandleSet& handleSet)
    : ParentType{}, aceHandleSetIter{ handleSet }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockAceHandleSetIterator)

Network::ACEHandle Network::SockAceHandleSetIterator::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceHandleSetIter();
}

#endif  // NETWORK_USE_ACE