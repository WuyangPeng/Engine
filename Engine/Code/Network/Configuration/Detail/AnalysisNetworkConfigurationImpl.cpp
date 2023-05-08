///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/04/28 10:43)

#include "Network/NetworkExport.h"

#include "AnalysisNetworkConfigurationImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

using namespace std::literals;

Network::AnalysisNetworkConfigurationImpl::AnalysisNetworkConfigurationImpl(std::string fileName)
    : container{}, fileName{ std::move(fileName) }, mainTree{}
{
    Analysis();

    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AnalysisNetworkConfigurationImpl)

void Network::AnalysisNetworkConfigurationImpl::Analysis()
{
    AnalysisJson();
    AnalysisMain();
}

void Network::AnalysisNetworkConfigurationImpl::AnalysisJson()
{
    read_json(fileName, mainTree);
}

void Network::AnalysisNetworkConfigurationImpl::AnalysisMain()
{
    for (const auto& tree : mainTree)
    {
        try
        {
            InsertStrategy(tree.first, tree.second);
        }
        catch (const CoreTools::Error& error)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, Network, SYSTEM_TEXT("网络策略"), tree.first, SYSTEM_TEXT("配置值错误："), error, CoreTools::LogAppenderIOManageSign::TriggerAssert);
        }
    }
}

void Network::AnalysisNetworkConfigurationImpl::InsertStrategy(const String& name, const BasicTree& basicTree)
{
    const auto wrappers = basicTree.get(SYSTEM_TEXT("Wrappers"s), String{});
    const auto connect = basicTree.get(SYSTEM_TEXT("Connect"s), String{});

    const auto wrappersStrategy = GetWrappersStrategy(wrappers);
    const auto connectStrategy = GetConnectStrategy(connect);

    const auto client = System::UnderlyingCastEnum<ClientStrategy>(basicTree.get(SYSTEM_TEXT("Client"s), 0));
    const auto server = System::UnderlyingCastEnum<ServerStrategy>(basicTree.get(SYSTEM_TEXT("Server"s), 0));
    const auto message = System::UnderlyingCastEnum<MessageStrategy>(basicTree.get(SYSTEM_TEXT("Message"s), 0));
    const auto parser = System::UnderlyingCastEnum<ParserStrategy>(basicTree.get(SYSTEM_TEXT("Parser"s), 0));
    const auto openSSL = System::UnderlyingCastEnum<OpenSSLStrategy>(basicTree.get(SYSTEM_TEXT("OpenSSL"s), 0));
    const auto encryptedCompression = System::UnderlyingCastEnum<EncryptedCompressionStrategy>(basicTree.get(SYSTEM_TEXT("EncryptedCompression"s), 0));
    const auto send = System::UnderlyingCastEnum<SocketSendMessage>(basicTree.get(SYSTEM_TEXT("Send"s), 0));

    if (ClientStrategy::Disable <= client &&
        client < ClientStrategy::End &&
        ServerStrategy::Disable <= server &&
        server < ServerStrategy::End &&
        message < MessageStrategy::End &&
        parser < ParserStrategy::End &&
        openSSL < OpenSSLStrategy::End)
    {
        const auto host = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("Host"s), String{}));
        const auto port = basicTree.get(SYSTEM_TEXT("Port"s), 0);
        const auto configurationSubStrategy = GetConfigurationSubStrategy(basicTree);
        const auto configurationParameter = GetConfigurationParameter(basicTree);

        if (server != ServerStrategy::Disable)
        {
            ConfigurationStrategy configurationStrategy(wrappersStrategy, connectStrategy, server, message, parser, openSSL, encryptedCompression, configurationSubStrategy, configurationParameter, send, host, port);

            container.emplace(name, configurationStrategy);
        }
        else if (client != ClientStrategy::Disable)
        {
            ConfigurationStrategy configurationStrategy(wrappersStrategy, connectStrategy, client, message, parser, openSSL, encryptedCompression, configurationSubStrategy, configurationParameter, send, host, port);

            container.emplace(name, configurationStrategy);
        }
        else
        {
            THROW_EXCEPTION(SYSTEM_TEXT("服务器和客户端策略都不存在。"s))
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("服务器和客户端策略无效。"s))
    }
}

Network::ConfigurationStrategy Network::AnalysisNetworkConfigurationImpl::GetConfigurationStrategy(const String& name) const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    if (const auto iter = container.find(name);
        iter != container.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("找不到指定名字的配置。"s))
    }
}

Network::WrappersStrategy Network::AnalysisNetworkConfigurationImpl::GetWrappersStrategy(const String& wrappers)
{
    if (const CoreTools::CaseInsensitiveTString caseInsensitiveTString{ wrappers.c_str() };
        caseInsensitiveTString == SYSTEM_TEXT("ACE"))
    {
        return WrappersStrategy::Ace;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("boost"))
    {
        return WrappersStrategy::Boost;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("beast"))
    {
        return WrappersStrategy::Beast;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("Network"))
    {
        return WrappersStrategy::Network;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("网络包装器类型不存在。"s))
}

Network::ConnectStrategy Network::AnalysisNetworkConfigurationImpl::GetConnectStrategy(const System::String& connect)
{
    if (const CoreTools::CaseInsensitiveTString caseInsensitiveTString{ connect.c_str() };
        caseInsensitiveTString == SYSTEM_TEXT("TCP"))
    {
        return ConnectStrategy::Tcp;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("UDP"))
    {
        return ConnectStrategy::Udp;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("http"))
    {
        return ConnectStrategy::Http;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("WebSocket"))
    {
        return ConnectStrategy::WebSocket;
    }
    else if (caseInsensitiveTString == SYSTEM_TEXT("KCP"))
    {
        return ConnectStrategy::Kcp;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("网络链接类型不存在。"s))
}

Network::ConfigurationSubStrategy Network::AnalysisNetworkConfigurationImpl::GetConfigurationSubStrategy(const BasicTree& basicTree)
{
    const auto wrappersSubTree = basicTree.get_child(SYSTEM_TEXT("WrappersSub"s));

    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    const auto sendBufferSize = (wrappersSubTree.get(SYSTEM_TEXT("SendBufferSize"s), 1048576));
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, sendBufferSize);

    const auto receiveBufferSize = (wrappersSubTree.get(SYSTEM_TEXT("ReceiveBufferSize"s), 1048576));
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, receiveBufferSize);

    const auto threads = (wrappersSubTree.get(SYSTEM_TEXT("Threads"s), 1));
    configurationSubStrategy.Insert(WrappersSubStrategy::Threads, threads);

    const auto multiContext = (wrappersSubTree.get(SYSTEM_TEXT("MultiContext"s), 0));
    configurationSubStrategy.Insert(WrappersSubStrategy::MultiContext, multiContext);

    return configurationSubStrategy;
}

Network::ConfigurationParameter Network::AnalysisNetworkConfigurationImpl::GetConfigurationParameter(const BasicTree& basicTree)
{
    const auto parameterTree = basicTree.get_child(SYSTEM_TEXT("Parameter"s));

    auto configurationParameter = ConfigurationParameter::Create();

    for (const auto& value : parameterTree)
    {
        configurationParameter.AddParameter(value.first, value.second.get_value<String>());
    }

    return configurationParameter;
}

Network::AnalysisNetworkConfigurationImpl::ContainerConstIter Network::AnalysisNetworkConfigurationImpl::begin() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return container.begin();
}

Network::AnalysisNetworkConfigurationImpl::ContainerConstIter Network::AnalysisNetworkConfigurationImpl::end() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return container.end();
}

int Network::AnalysisNetworkConfigurationImpl::GetSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(container.size());
}
