///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/04/28 09:48)

#include "Network/NetworkExport.h"

#include "ConfigurationHostPort.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Network::ConfigurationHostPort::ConfigurationHostPort(string host, int port) noexcept
    : host{ std::move(host) }, port{ port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationHostPort::ConfigurationHostPort() noexcept
    : host{}, port{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationHostPort)

string Network::ConfigurationHostPort::GetHost() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return host;
}

int Network::ConfigurationHostPort::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return port;
}