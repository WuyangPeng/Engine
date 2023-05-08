///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 09:48)

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
