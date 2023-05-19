///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 13:54)

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