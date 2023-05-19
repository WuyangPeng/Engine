///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/09 09:17)

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

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Acceptor�࣡"s))
}

Network::BoostHandleType Network::SockAcceptorImpl::GetBoostHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost Acceptor�࣡"s))
}

Network::WinSocketType Network::SockAcceptorImpl::GetWinSocket()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����Network Acceptor�࣡"s))
}
