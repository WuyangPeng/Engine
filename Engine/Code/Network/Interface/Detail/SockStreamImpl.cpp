//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 12:54)

#include "Network/NetworkExport.h"

#include "SockStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamImpl)

Network::ACESockStreamNativeType& Network::SockStreamImpl::GetACESockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s));
}

Network::ACEHandleType Network::SockStreamImpl::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s));
}

void Network::SockStreamImpl::SetACEHandle([[maybe_unused]] ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s));
}

void Network::SockStreamImpl::SetNetworkHandle([[maybe_unused]] WinSocketStreamType winSocket)
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"s));
}

Network::BoostSockStreamType& Network::SockStreamImpl::GetBoostSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost Stream�࣡"s));
}

Network::WinSocketStreamType& Network::SockStreamImpl::GetNetworkSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"s));
}
