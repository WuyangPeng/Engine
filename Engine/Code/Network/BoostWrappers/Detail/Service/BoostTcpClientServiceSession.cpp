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
#include "CoreTools/CharacterString/StringConversion.h"
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

void Network::BoostTcpClientServiceSession::Response(const std::function<void(const std::string&)>& processDataCallback)
{
    NETWORK_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        return DoResponse(processDataCallback);
    }
    EXCEPTION_ALL_CATCH(Network)
}

void Network::BoostTcpClientServiceSession::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    context.run();
}

void Network::BoostTcpClientServiceSession::Stop()
{
    NETWORK_CLASS_IS_VALID_9;

    context.stop();
}

void Network::BoostTcpClientServiceSession::Close()
{
    NETWORK_CLASS_IS_VALID_9;

    socket.close();
}

void Network::BoostTcpClientServiceSession::DoResponse(const std::function<void(const std::string&)>& processDataCallback)
{
    /// 异步读取，直到遇到分隔符
    async_read_until(socket, response, "\r\n",
                     [processDataCallback, this](const boost::system::error_code& error, size_t bytesTransferred) {
                         System::UnusedFunction(bytesTransferred);

                         if (!error)
                         {
                             std::string result{};
                             result.resize(response.size());

                             const auto buffers = response.data();
                             buffer_copy(boost::asio::buffer(result), buffers);

                             response.consume(response.size());

                             /// 调用回调函数处理数据
                             processDataCallback(result);
                         }
                         else
                         {
                             THROW_EXCEPTION(SYSTEM_TEXT("response error =") + CoreTools::StringConversion::MultiByteConversionStandard(error.message()))
                         }
                     });
}