/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:30)

#include "Network/NetworkExport.h"

#include "SockAceHandleSet.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#ifdef NETWORK_USE_ACE

Network::SockAceHandleSet::SockAceHandleSet() noexcept
    : ParentType{}, aceHandleSet{}
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, SockAceHandleSet)

void Network::SockAceHandleSet::SetBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.set_bit(handle);
}

int64_t Network::SockAceHandleSet::GetMaxSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    #ifdef TCRE_USE_GCC

    return aceHandleSet.max_set();

    #else  // !TCRE_USE_GCC

        #include SYSTEM_WARNING_PUSH
        #include SYSTEM_WARNING_DISABLE(26490)

    return reinterpret_cast<int64_t>(aceHandleSet.max_set());

        #include SYSTEM_WARNING_POP

    #endif  // TCRE_USE_GCC
}

Network::SockFdSet* Network::SockAceHandleSet::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    return aceHandleSet.fdset();
}

void Network::SockAceHandleSet::Sync(ACEHandleType maxHandle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.sync(maxHandle);
}

bool Network::SockAceHandleSet::IsSet(ACEHandleType handle) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet.is_set(handle) != 0;
}

void Network::SockAceHandleSet::ClearBit(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    aceHandleSet.clr_bit(handle);
}

Network::SockAceHandleSet::ImplTypeSharedPtr Network::SockAceHandleSet::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::SockAceHandleSet::GetACEHandleSet() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet;
}

bool Network::SockAceHandleSet::IsFdSetFull() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (FD_SETSIZE <= aceHandleSet.num_set())
        return true;
    else
        return false;
}

int Network::SockAceHandleSet::IsFdSetCount() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return aceHandleSet.num_set();
}

bool Network::SockAceHandleSet::Select(int width)
{
    NETWORK_CLASS_IS_VALID_9;

    if (0 < ACE::select(width, aceHandleSet))
        return true;
    else
        return false;
}

#endif  // NETWORK_USE_ACE