/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.1 (2024/09/14 11:15)

#include "Network/NetworkExport.h"

#include "BoostTcpClientServiceSession.h"
#include "System/Helper/PragmaWarning/Asio.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

Network::BoostTcpClientServiceSession::BoostTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      context{},
      socket{ context }
{
    Connect();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::BoostTcpClientServiceSession::Connect()
{
    boost::asio::ip::tcp::resolver resolver{ context };
    const auto endPoints = resolver.resolve(GetHost(), std::to_string(GetPort()));

    boost::asio::connect(socket, endPoints);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpClientServiceSession)

void Network::BoostTcpClientServiceSession::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    socket.write_some(boost::asio::buffer(message));
}

std::string Network::BoostTcpClientServiceSession::Response()
{
    NETWORK_CLASS_IS_VALID_9;

    try
    {
        return DoResponse();
    }
    catch (std::exception& exception)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("消息接收失败："), exception, CoreTools::LogAppenderIOManageSign::TriggerAssert);
    }

    return "";
}

std::string Network::BoostTcpClientServiceSession::DoResponse()
{
    boost::asio::streambuf response{};
    read_until(socket, response, "\r\n");

    std::string result{};
    result.resize(response.size());

    const auto buffers = response.data();
    buffer_copy(boost::asio::buffer(result), buffers);

    return result;
}