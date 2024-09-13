/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:24)

#include "Network/NetworkExport.h"

#include "BoostTcpClientServiceSession.h"
#include "System/Helper/PragmaWarning/AsioConnect.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BoostTcpClientServiceSession::BoostTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      context{},
      socket{ context },
      thread{ [](IoContextType& aContext) {
                 aContext.run();
             },
              std::ref(context) }
{
    Connect();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostTcpClientServiceSession::~BoostTcpClientServiceSession() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Join();
    }
    EXCEPTION_ALL_CATCH(Network)
}

void Network::BoostTcpClientServiceSession::Connect()
{
    boost::asio::ip::tcp::resolver resolver{ context };
    const auto endPoints = resolver.resolve(GetHost(), std::to_string(GetPort()));

    boost::asio::connect(socket, endPoints);
}

void Network::BoostTcpClientServiceSession::Join()
{
    thread.join();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpClientServiceSession)

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void response(boost::asio::ip::tcp::socket& socket)
{
    try
    {
        // 等待服务器响应
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // 使用std::istream从streambuf读取数据
        std::istream response_stream(&response);
        std::string line;
        // 读取并打印每一行
        while (std::getline(response_stream, line))
        {
            std::cout << "Server response: " << line << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

void Network::BoostTcpClientServiceSession::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    boost::asio::write(socket, boost::asio::buffer(message));

    response(socket);
}
