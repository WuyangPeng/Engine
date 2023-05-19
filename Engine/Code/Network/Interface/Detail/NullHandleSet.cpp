///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 09:53)

#include "Network/NetworkExport.h"

#include "NullHandleSet.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, NullHandleSet)

void Network::NullHandleSet::SetBit(ACEHandleType handle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(handle);
}

int64_t Network::NullHandleSet::GetMaxSet() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}

Network::SockFdSet* Network::NullHandleSet::GetFdSet()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取fdset失败！"s))
}

void Network::NullHandleSet::Sync(ACEHandleType maxHandle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(maxHandle);
}

bool Network::NullHandleSet::IsSet(ACEHandleType handle) const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    System::UnusedFunction(handle);

    return false;
}

void Network::NullHandleSet::ClearBit(ACEHandleType handle) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(handle);
}

Network::NullHandleSet::ImplTypeSharedPtr Network::NullHandleSet::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

const Network::ACEHandleSet& Network::NullHandleSet::GetACEHandleSet() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("获取ACEHandleSet失败！"s))
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

bool Network::NullHandleSet::Select(int width) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(width);

    return false;
}
