///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 18:07)

#include "Network/NetworkExport.h"

#include "NullHandleSet.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;

CLASS_INVARIANT_STUB_DEFINE(Network, NullHandleSet)

void Network::NullHandleSet::SetBit(MAYBE_UNUSED ACEHandle handle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

int64_t Network::NullHandleSet::GetMaxSet() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

Network::SockFdSet* Network::NullHandleSet::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取fdset失败！"s));
}

void Network::NullHandleSet::Sync(MAYBE_UNUSED ACEHandle maxHandle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

bool Network::NullHandleSet::IsSet(MAYBE_UNUSED ACEHandle handle) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return false;
}

void Network::NullHandleSet::ClearBit(MAYBE_UNUSED ACEHandle handle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;
}

Network::NullHandleSet::ImplTypeSharedPtr Network::NullHandleSet::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::NullHandleSet::GetACEHandleSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取ACEHandleSet失败！"s));
}

bool Network::NullHandleSet::IsFdSetFull() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return true;
}

int Network::NullHandleSet::IsFdSetCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

bool Network::NullHandleSet::Select(MAYBE_UNUSED int width) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return false;
}
