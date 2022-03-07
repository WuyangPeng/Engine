///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/17 13:50)

#include "Network/NetworkExport.h"

#include "ConfigurationIPPort.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Network::ConfigurationIPPort::ConfigurationIPPort(string ip, int port) noexcept
    : ip{ std::move(ip) }, port{ port }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ConfigurationIPPort::ConfigurationIPPort() noexcept
    : ip{}, port{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, ConfigurationIPPort)

string Network::ConfigurationIPPort::GetIP() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return ip;
}

int Network::ConfigurationIPPort::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return port;
}
