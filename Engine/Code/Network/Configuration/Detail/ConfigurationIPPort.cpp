//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/26 19:11)

#include "Network/NetworkExport.h"

#include "ConfigurationIPPort.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Network::ConfigurationIPPort::ConfigurationIPPort(const string& ip, int port)
    : m_IP{ ip }, m_Port{ port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationIPPort::ConfigurationIPPort() noexcept
    : m_IP{}, m_Port{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationIPPort)

string Network::ConfigurationIPPort::GetIP() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_IP;
}

int Network::ConfigurationIPPort::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Port;
}
