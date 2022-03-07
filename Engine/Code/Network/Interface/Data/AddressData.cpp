///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 17:13)

#include "Network/NetworkExport.h"

#include "AddressData.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/BoostWrappers/Detail/Acceptor/BoostSockAcceptor.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

using std::string;

Network::AddressData::AddressData(const string& address, int port)
    : address{ address }, port{ port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const SockStream& sockStream)
    : address{ sockStream.GetRemoteAddress() }, port{ sockStream.GetRemotePort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const BoostSockAcceptor& boostSockAcceptor)
    : address{ boostSockAcceptor.GetAddress() }, port{ boostSockAcceptor.GetPort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const BoostSockStream& boostSockStream)
    : address{ boostSockStream.GetRemoteAddress() }, port{ boostSockStream.GetRemotePort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const SockAddress& sockAddress)
    : address{ sockAddress.GetAddress() }, port{ sockAddress.GetPort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AddressData)

string Network::AddressData::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return address;
}

int Network::AddressData::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return port;
}
