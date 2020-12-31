//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:54)

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

void Network::SockStreamImpl::SetACEHandle([[maybe_unused]] ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Stream类！"s));
}

void Network::SockStreamImpl::SetNetworkHandle([[maybe_unused]] WinSocketStreamType winSocket)
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
