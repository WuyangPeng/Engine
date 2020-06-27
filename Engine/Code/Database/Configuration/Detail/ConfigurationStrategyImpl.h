// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 10:52)

#ifndef DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
#define DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/Configuration/Flags/ConfigurationStrategyFlags.h" 

#include <map>
#include <string>
#include <vector>

namespace Database
{
	class DATABASE_HIDDEN_DECLARE ConfigurationStrategyImpl
	{
	public:
		using ClassType = ConfigurationStrategyImpl;
		using FlagsOption = std::vector<std::string>;
		using StringOption = std::map<std::string, std::string>;
		using BooleanOption = std::map<std::string, bool>;
		using IntOption = std::map<std::string, int>;
		using SSLOption = std::map<std::string, std::string>;
		using DBMapping = std::map<int, std::string>;

	public:
		ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
								  const std::string& hostName, const std::string& userName, const std::string& password);
		ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const std::string& ip, int port,
								  const std::string& hostName, const std::string& userName, const std::string& password,
								  bool pooling, int poolMaxSize, int poolQueueTimeout, int poolMaxIdleTime,
								  const FlagsOption& flagsOption, const StringOption& stringOption, const BooleanOption& booleanOption,
								  const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping);

		CLASS_INVARIANT_DECLARE;

		WrappersStrategy GetWrappersStrategy() const;

		std::string GetIP() const;
		int GetPort() const;
		std::string GetDBHostName() const;
		std::string GetDBUserName() const;
		std::string GetDBPassword() const;

		FlagsOption GetFlagsOption() const;
		StringOption GetStringOptions() const;
		BooleanOption GetBooleanOptions() const;
		IntOption GetIntOptions() const;
		SSLOption GetSSLOptions() const;
		DBMapping GetDBMapping() const;
		bool IsUseSSL() const;
		std::string GetDBName(int dbIndex) const;

		bool GetPooling() const;
		int GetPoolMaxSize() const;
		int GetPoolQueueTimeout() const;
		int GetPoolMaxIdleTime() const;

	private:
		WrappersStrategy m_WrappersStrategyFlag;
		std::string m_IP;
		int m_Port;
		std::string m_HostName;
		std::string m_UserName;
		std::string m_Password;
		bool m_Pooling;
		int m_PoolMaxSize;
		int m_PoolQueueTimeout;
		int m_PoolMaxIdleTime;

		FlagsOption m_FlagsOptions;
		StringOption m_StringOptions;
		BooleanOption m_BooleanOptions;
		IntOption m_IntOptions;
		SSLOption m_SSLOptions;
		DBMapping m_DBMapping;
	};
}

#endif // DATABASE_DATABASE_CONFIGURATION_CONFIGURATION_STRATEGY_IMPL_H
