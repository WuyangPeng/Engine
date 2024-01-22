/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:30)

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