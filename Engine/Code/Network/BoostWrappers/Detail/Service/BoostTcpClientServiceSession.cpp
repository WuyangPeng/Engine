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

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

void response(boost::asio::ip::tcp::socket& socket)
{
    try
    {
        boost::asio::streambuf response;
        boost::asio::read_until(socket, response, "\r\n");

        std::istream response_stream(&response);
        std::string line;
        while (std::getline(response_stream, line))
        {
            std::cout << "Server response: " << line << std::endl;

            // ����״̬��
            if (line.size() >= 3 && std::isdigit(line[0]) && std::isdigit(line[1]) && std::isdigit(line[2]))
            {
                int statusCode = std::stoi(line.substr(0, 3));
                if (statusCode >= 200 && statusCode < 300)
                {
                    // 2xx ��Ӧ�������ɹ�
                }
                else if (statusCode >= 300 && statusCode < 400)
                {
                    // 3xx ��Ӧ����Ҫ��һ������
                }
                else if (statusCode >= 400 && statusCode < 500)
                {
                    // 4xx ��Ӧ����ʱ����
                }
                else if (statusCode >= 500 && statusCode < 600)
                {
                    // 5xx ��Ӧ�����ô���
                }
            }
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

    response(socket);

    socket.write_some(boost::asio::buffer(message));
}
