// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/03 09:46)

#include "Database/DatabaseExport.h" 

#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

using std::string;  
using std::vector;
using std::map;

Database::ConfigurationStrategyImpl
	::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const string& ip, uint32_t port,
		                        const string& hostName, const string& userName, const string& password)
	:m_WrappersStrategyFlag{ wrappersStrategy },
	 m_IP{ ip },
	 m_Port{ port },
	 m_HostName{ hostName },
	 m_UserName{ userName },
	 m_Password{ password },
	 m_Pooling{ false },
     m_PoolMaxSize{ 0 },
     m_PoolQueueTimeout{ 0 },
     m_PoolMaxIdleTime{ 0 },
	 m_FlagsOptions{ },
	 m_StringOptions{},
	 m_BooleanOptions{},
	 m_IntOptions{},
	 m_SSLOptions{},
	 m_DBMapping{}
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ConfigurationStrategyImpl
	::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const string& ip, uint32_t port,
		                        const string& hostName, const string& userName, const string& password,	
		                        bool pooling, int poolMaxSize, int poolQueueTimeout, int poolMaxIdleTime,
		                        const FlagsOption& flagsOption, const StringOption& stringOption, const BooleanOption& booleanOption,
		                        const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping)
	:m_WrappersStrategyFlag{ wrappersStrategy },
	 m_IP{ ip },
	 m_Port{ port },
	 m_HostName{ hostName },
	 m_UserName{ userName },
	 m_Password{ password },
	 m_Pooling{ pooling },
	 m_PoolMaxSize{ poolMaxSize },
	 m_PoolQueueTimeout{ poolQueueTimeout },
	 m_PoolMaxIdleTime{ poolMaxIdleTime },
	 m_FlagsOptions{ flagsOption },
	 m_StringOptions{ stringOption },
	 m_BooleanOptions{ booleanOption },
	 m_IntOptions{ intOption },
	 m_SSLOptions{ sslOption },
	 m_DBMapping{ dbMapping }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database,ConfigurationStrategyImpl)

Database::WrappersStrategy Database::ConfigurationStrategyImpl
	::GetWrappersStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_WrappersStrategyFlag;
}

string Database::ConfigurationStrategyImpl
	::GetIP() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_IP;
}

uint32_t Database::ConfigurationStrategyImpl
	::GetPort() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_Port;
}

string Database::ConfigurationStrategyImpl
	::GetDBHostName() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_HostName;
}

string Database::ConfigurationStrategyImpl
	::GetDBUserName() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_UserName;
}

string Database::ConfigurationStrategyImpl
	::GetDBPassword() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_Password;
}

Database::ConfigurationStrategyImpl::FlagsOption Database::ConfigurationStrategyImpl
	::GetFlagsOption() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_FlagsOptions;
}

Database::ConfigurationStrategyImpl::StringOption Database::ConfigurationStrategyImpl
	::GetStringOptions() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_StringOptions;
}

Database::ConfigurationStrategyImpl::BooleanOption Database::ConfigurationStrategyImpl
	::GetBooleanOptions() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_BooleanOptions;
}

Database::ConfigurationStrategyImpl::IntOption Database::ConfigurationStrategyImpl
	::GetIntOptions() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_IntOptions;
}

Database::ConfigurationStrategyImpl::SSLOption Database::ConfigurationStrategyImpl
	::GetSSLOptions() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_SSLOptions;
}

bool Database::ConfigurationStrategyImpl
	::IsUseSSL() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return !m_SSLOptions.empty();
}

Database::ConfigurationStrategyImpl::DBMapping Database::ConfigurationStrategyImpl
	::GetDBMapping() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_DBMapping;
}

std::string Database::ConfigurationStrategyImpl
	::GetDBName(int dbIndex) const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	auto iter = m_DBMapping.find(dbIndex);
	if (iter != m_DBMapping.cend())
	{
		return iter->second;
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("δ�ҵ�ָ�������ݿ�������"));
	}
}

bool Database::ConfigurationStrategyImpl
	::GetPooling() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_Pooling;
}

int Database::ConfigurationStrategyImpl
	::GetPoolMaxSize() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_PoolMaxSize;
}

int Database::ConfigurationStrategyImpl
	::GetPoolQueueTimeout() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_PoolQueueTimeout;
}

int Database::ConfigurationStrategyImpl
	::GetPoolMaxIdleTime() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_PoolMaxIdleTime;
}
