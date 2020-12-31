//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 12:51)

#include "Network/NetworkExport.h"

#include "SockAcceptorImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::SockAcceptorImpl::SockAcceptorImpl() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, SockAcceptorImpl)

Network::ACEHandleType Network::SockAcceptorImpl::GetACEHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是ACE Acceptor类！"s));
}

Network::BoostHandleType Network::SockAcceptorImpl::GetBoostHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是boost Acceptor类！"s));
}

Network::WinSocketType Network::SockAcceptorImpl::GetWinSocket()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("不是Network Acceptor类！"s));
}
