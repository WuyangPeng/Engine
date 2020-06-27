// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/10 12:31)

#include "Network/NetworkExport.h" 

#include "AnalysisNetworkConfigurationImpl.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/CharacterString/CaseInsensitiveStringDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

#include "System/Helper/PragmaWarning/NumericCast.h" 

using std::string;

Network::AnalysisNetworkConfigurationImpl
	::AnalysisNetworkConfigurationImpl(const string& fileName)
	:m_Container{}, m_FileName{ fileName }, m_MainTree{}
{
	Analysis();

	NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Network, AnalysisNetworkConfigurationImpl)

// private
void Network::AnalysisNetworkConfigurationImpl
	::Analysis()
{
	AnalysisJson();
	AnalysisMain();
}

// private
void Network::AnalysisNetworkConfigurationImpl
	::AnalysisJson()
{
	read_json(m_FileName, m_MainTree);
}

// private
void Network::AnalysisNetworkConfigurationImpl
	::AnalysisMain()
{
	for (const auto& ptree : m_MainTree)
	{
		try
		{
			InsertStrategy(ptree.first, ptree.second);
		}
		catch (CoreTools::Error& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Warn, Network)
				<< SYSTEM_TEXT("网络策略")
				<< ptree.first
				<< SYSTEM_TEXT("配置值错误：")
				<< error
				<< CoreTools::LogAppenderIOManageSign::TriggerAssert;
		}
	}
}

// private
void Network::AnalysisNetworkConfigurationImpl
	::InsertStrategy(const String& name, const BasicTree& basicTree)
{
	auto wrappers = basicTree.get(SYSTEM_TEXT("Wrappers"), String{});
	auto connect = basicTree.get(SYSTEM_TEXT("Connect"), String{});

	auto wrappersStrategy = GetWrappersStrategy(wrappers);
	auto connectStrategy = GetConnectStrategy(connect);

	auto client = basicTree.get(SYSTEM_TEXT("Client"), ClientStrategy::Disable);
	auto server = basicTree.get(SYSTEM_TEXT("Server"), ServerStrategy::Disable);
	auto message = basicTree.get(SYSTEM_TEXT("Message"), MessageStrategy::Default);
	auto parser = basicTree.get(SYSTEM_TEXT("Parser"), ParserStrategy::LittleEndian);
	auto openSSL = basicTree.get(SYSTEM_TEXT("OpenSSL"), OpenSSLStrategy::Default);
	auto send = basicTree.get(SYSTEM_TEXT("Send"), SocketSendMessage::Default);

	if (ClientStrategy::Disable <= client && client < ClientStrategy::End &&
		ServerStrategy::Disable <= server && server < ServerStrategy::End &&
		message < MessageStrategy::End && parser < ParserStrategy::End && openSSL < OpenSSLStrategy::End)
	{
		auto ip = CoreTools::StringConversion::StandardConversionMultiByte(basicTree.get(SYSTEM_TEXT("IP"), String{}));
		auto port = basicTree.get(SYSTEM_TEXT("Port"), 0);
		auto configurationSubStrategy = GetConfigurationSubStrategy(basicTree);
		auto configurationParameter = GetConfigurationParameter(basicTree);

		if (server != ServerStrategy::Disable)
		{
			ConfigurationStrategy configurationStrategy(wrappersStrategy, connectStrategy, server, message, parser, openSSL, configurationSubStrategy, configurationParameter, send, ip, port);

			m_Container.insert({ name, configurationStrategy });
		}
		else if (client != ClientStrategy::Disable)
		{
			ConfigurationStrategy configurationStrategy(wrappersStrategy, connectStrategy, client, message, parser, openSSL, configurationSubStrategy, configurationParameter, send, ip, port);

			m_Container.insert({ name, configurationStrategy });
		}
		else
		{
			THROW_EXCEPTION(SYSTEM_TEXT("服务器和客户端策略都不存在。"));
		}
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("服务器和客户端策略无效。"));
	}
}

Network::ConfigurationStrategy Network::AnalysisNetworkConfigurationImpl
	::GetConfigurationStrategy(const String& name) const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto iter = m_Container.find(name);

	if (iter != m_Container.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("找不到指定名字的配置。"));
	}
}

Network::WrappersStrategy Network::AnalysisNetworkConfigurationImpl
	::GetWrappersStrategy(const String& wrappers)
{
	CoreTools::CaseInsensitiveTString caseInsensitiveTString{ wrappers.c_str() };

	if (caseInsensitiveTString == SYSTEM_TEXT("ACE"))
	{
		return WrappersStrategy::ACE;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("boost"))
	{
		return WrappersStrategy::Boost;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("Network"))
	{
		return WrappersStrategy::Network;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("Socket"))
	{
		return WrappersStrategy::Socket;
	}

	THROW_EXCEPTION(SYSTEM_TEXT("网络包装器类型不存在。"));
}

Network::ConnectStrategy Network::AnalysisNetworkConfigurationImpl
	::GetConnectStrategy(const System::String& connect)
{
	CoreTools::CaseInsensitiveTString caseInsensitiveTString{ connect.c_str() };

	if (caseInsensitiveTString == SYSTEM_TEXT("TCP"))
	{
		return ConnectStrategy::TCP;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("UDP"))
	{
		return ConnectStrategy::UDP;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("http"))
	{
		return ConnectStrategy::Http;
	}
	else if (caseInsensitiveTString == SYSTEM_TEXT("WebSocket"))
	{
		return ConnectStrategy::WebSocket;
	}

	THROW_EXCEPTION(SYSTEM_TEXT("网络链接类型不存在。"));
}

Network::ConfigurationSubStrategy Network::AnalysisNetworkConfigurationImpl
	::GetConfigurationSubStrategy(const BasicTree& basicTree)
{
	auto wrappersSubTree = basicTree.get_child(SYSTEM_TEXT("WrappersSub"));

	ConfigurationSubStrategy configurationSubStrategy{};

	auto threads = (wrappersSubTree.get(SYSTEM_TEXT("Threads"), 0u));
	if (0 < threads)
	{
		configurationSubStrategy.Insert(WrappersSubStrategy::Threads, threads);
	}
	auto multiContext = (wrappersSubTree.get(SYSTEM_TEXT("MultiContext"), 0u));
	if (0 < multiContext)
	{
		configurationSubStrategy.Insert(WrappersSubStrategy::MultiContext, multiContext);
	}

	return configurationSubStrategy;
}

Network::ConfigurationParameter Network::AnalysisNetworkConfigurationImpl
	::GetConfigurationParameter(const BasicTree& basicTree)
{
	auto parameterTree = basicTree.get_child(SYSTEM_TEXT("Parameter"));

	ConfigurationParameter configurationParameter{};

	for (const auto& value : parameterTree)
	{
		configurationParameter.AddParameter(value.first, value.second.get_value<String>());
	}

	return configurationParameter;
}

Network::AnalysisNetworkConfigurationImpl::ContainerConstIter Network::AnalysisNetworkConfigurationImpl
	::GetBegin() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Container.begin();
}

Network::AnalysisNetworkConfigurationImpl::ContainerConstIter Network::AnalysisNetworkConfigurationImpl
	::GetEnd() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Container.end();
}

int Network::AnalysisNetworkConfigurationImpl
	::GetSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Container.size());
}

