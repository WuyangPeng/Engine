/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:28)

#include "Network/NetworkExport.h"

#include "SockStreamImpl.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CLASS_INVARIANT_STUB_DEFINE(Network, SockStreamImpl)

Network::ACESockStreamNativeType& Network::SockStreamImpl::GetACESockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s))
}

Network::ACEHandleType Network::SockStreamImpl::GetACEHandle() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s))
}

void Network::SockStreamImpl::SetACEHandle(ACEHandleType handle)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(handle);

    THROW_EXCEPTION(SYSTEM_TEXT("����ACE Stream�࣡"s))
}

void Network::SockStreamImpl::SetNetworkHandle(WinSocketStreamType winSocket)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(winSocket);

    THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"s))
}

Network::BoostSockStreamType& Network::SockStreamImpl::GetBoostSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����boost Stream�࣡"s))
}

Network::WinSocketStreamType& Network::SockStreamImpl::GetNetworkSockStream()
{
    NETWORK_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("����Network Stream�࣡"s))
}
