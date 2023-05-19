///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 13:53)

#include "Network/NetworkExport.h"

#include "SockACEHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::SockACEHandleSet::SockACEHandleSet() noexcept
    : ParentType{}, aceHandleSet{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockACEHandleSet)

void Network::SockACEHandleSet::SetBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.set_bit(handle);
}

int64_t Network::SockACEHandleSet::GetMaxSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    #include STSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<int64_t>(aceHandleSet.max_set());

    #include STSTEM_WARNING_POP
}

Network::SockFdSet* Network::SockACEHandleSet::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceHandleSet.fdset();
}

void Network::SockACEHandleSet::Sync(ACEHandleType maxHandle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.sync(maxHandle);
}

bool Network::SockACEHandleSet::IsSet(ACEHandleType handle) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet.is_set(handle) != 0;
}

void Network::SockACEHandleSet::ClearBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.clr_bit(handle);
}

Network::SockACEHandleSet::ImplTypeSharedPtr Network::SockACEHandleSet::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::SockACEHandleSet::GetACEHandleSet() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet;
}

bool Network::SockACEHandleSet::IsFdSetFull() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (FD_SETSIZE <= aceHandleSet.num_set())
        return true;
    else
        return false;
}

int Network::SockACEHandleSet::IsFdSetCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet.num_set();
}

bool Network::SockACEHandleSet::Select(int width)
{
    NETWORK_CLASS_IS_VALID_9;

    if (0 < ACE::select(width, aceHandleSet))
        return true;
    else
        return false;
}

#endif  // NETWORK_USE_ACE