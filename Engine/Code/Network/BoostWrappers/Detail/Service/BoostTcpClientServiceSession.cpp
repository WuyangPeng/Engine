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
#include "Network/Interface/BaseMainManager.h"

Network::BoostTcpClientServiceSession::BoostTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      socket{ BASE_MAIN_MANAGER_SINGLETON.GetContext() }
{
    Connect();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::BoostTcpClientServiceSession::Connect()
{
    boost::asio::ip::tcp::resolver resolver{ BASE_MAIN_MANAGER_SINGLETON.GetContext() };
    const auto endPoints = resolver.resolve(GetHost(), std::to_string(GetPort()));

    boost::asio::connect(socket, endPoints);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostTcpClientServiceSession)

void Network::BoostTcpClientServiceSession::SendTextMessage(const std::string& message)
{
    NETWORK_CLASS_IS_VALID_9;

    socket.send(boost::asio::buffer(message));
}
