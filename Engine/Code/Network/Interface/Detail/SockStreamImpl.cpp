///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/21 16:57)

#include "Network/NetworkExport.h"

#include "SockStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamImpl)

Network::ACESockStreamNativeType& Network::SockStreamImpl::GetACESockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"s));
}

Network::ACEHandleType Network::SockStreamImpl::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"s));
}

void Network::SockStreamImpl::SetACEHandle(MAYBE_UNUSED ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"s));
}

void Network::SockStreamImpl::SetNetworkHandle(MAYBE_UNUSED WinSocketStreamType winSocket)
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是Network Stream类！"s));
}

Network::BoostSockStreamType& Network::SockStreamImpl::GetBoostSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是boost Stream类！"s));
}

Network::WinSocketStreamType& Network::SockStreamImpl::GetNetworkSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是Network Stream类！"s));
}
