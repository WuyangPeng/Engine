//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 10:52)

#include "Network/NetworkExport.h"

#include "AddressData.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/BoostWrappers/Detail/Acceptor/BoostSockAcceptor.h"
#include "Network/BoostWrappers/Detail/Stream/BoostSockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

using std::string;

Network::AddressData::AddressData(const string& address, int port)
    : m_Address{ address }, m_Port{ port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const SockStream& sockStream)
    : m_Address{ sockStream.GetRemoteAddress() }, m_Port{ sockStream.GetRemotePort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const BoostSockAcceptor& boostSockAcceptor)
    : m_Address{ boostSockAcceptor.GetAddress() }, m_Port{ boostSockAcceptor.GetPort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const BoostSockStream& boostSockStream)
    : m_Address{ boostSockStream.GetRemoteAddress() }, m_Port{ boostSockStream.GetRemotePort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::AddressData::AddressData(const SockAddress& sockAddress)
    : m_Address{ sockAddress.GetAddress() }, m_Port{ sockAddress.GetPort() }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AddressData)

string Network::AddressData::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Address;
}

int Network::AddressData::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Port;
}
