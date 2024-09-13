/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 17:24)

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
        // �ȴ���������Ӧ
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        // ʹ��std::istream��streambuf��ȡ����
        std::istream response_stream(&response);
        std::string line;
        // ��ȡ����ӡÿһ��
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
