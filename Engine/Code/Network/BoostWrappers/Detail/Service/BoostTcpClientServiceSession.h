/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:22)

#ifndef NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H
#define NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H

#include "Network/NetworkDll.h"

#include "System/Helper/PragmaWarning/Asio.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/ServiceWrappers/Detail/ClientServiceSession.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostTcpClientServiceSession final : public ClientServiceSession
    {
    public:
        using ClassType = BoostTcpClientServiceSession;
        using ParentType = ClientServiceSession;

    public:
        explicit BoostTcpClientServiceSession(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void SendTextMessage(const std::string& message) override;
        void Response(const std::function<void(const std::string&)>& processDataCallback) override;
        void Run() override;
        void Stop() override;
        void Close() override;

    private:
        void Connect();
        void DoResponse(const std::function<void(const std::string&)>& processDataCallback);

    private:
        IoContextType context;
        BoostSockStreamType socket;
        boost::asio::streambuf response;
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_ACE_TCP_CLIENT_SERVICE_SESSION_H
