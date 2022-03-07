///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 17:55)

#include "Network/NetworkExport.h"

#include "SockACEHandleSetIterator.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::SockACEHandleSetIterator::SockACEHandleSetIterator(const ACEHandleSet& handleSet)
    : ParentType{}, aceHandleSetIter{ handleSet }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSetIterator)

Network::ACEHandle Network::SockACEHandleSetIterator::operator()()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceHandleSetIter();
}

#endif  // NETWORK_USE_ACE