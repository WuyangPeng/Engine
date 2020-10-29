//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 20:29)

#include "Database/DatabaseExport.h"

#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::map;
using std::string;
using std::vector;

Database::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const string& ip, int port,
                                                               const string& hostName, const string& userName, const string& password)
    : m_WrappersStrategyFlag{ wrappersStrategy }, m_IP{ ip }, m_Port{ port },
      m_HostName{ hostName }, m_UserName{ userName }, m_Password{ password },
      m_Pooling{ false }, m_PoolMaxSize{ 0 }, m_PoolQueueTimeout{ 0 },
      m_PoolMaxIdleTime{ 0 }, m_FlagsOptions{}, m_StringOptions{},
      m_BooleanOptions{}, m_IntOptions{}, m_SSLOptions{}, m_DBMapping{}
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy, const string& ip, int port,
                                                               const string& hostName, const string& userName, const string& password,
                                                               bool pooling, int poolMaxSize, int poolQueueTimeout, int poolMaxIdleTime,
                                                               const FlagsOption& flagsOption, const StringOption& stringOption, const BooleanOption& booleanOption,
                                                               const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping)
    : m_WrappersStrategyFlag{ wrappersStrategy }, m_IP{ ip },
      m_Port{ port }, m_HostName{ hostName }, m_UserName{ userName },
      m_Password{ password }, m_Pooling{ pooling }, m_PoolMaxSize{ poolMaxSize },
      m_PoolQueueTimeout{ poolQueueTimeout }, m_PoolMaxIdleTime{ poolMaxIdleTime }, m_FlagsOptions{ flagsOption },
      m_StringOptions{ stringOption }, m_BooleanOptions{ booleanOption }, m_IntOptions{ intOption },
      m_SSLOptions{ sslOption }, m_DBMapping{ dbMapping }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ConfigurationStrategyImpl)

Database::WrappersStrategy Database::ConfigurationStrategyImpl::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_WrappersStrategyFlag;
}

string Database::ConfigurationStrategyImpl::GetIP() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_IP;
}

int Database::ConfigurationStrategyImpl::GetPort() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Port;
}

string Database::ConfigurationStrategyImpl::GetDBHostName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_HostName;
}

string Database::ConfigurationStrategyImpl::GetDBUserName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_UserName;
}

string Database::ConfigurationStrategyImpl::GetDBPassword() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Password;
}

Database::ConfigurationStrategyImpl::FlagsOption Database::ConfigurationStrategyImpl::GetFlagsOption() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_FlagsOptions;
}

Database::ConfigurationStrategyImpl::StringOption Database::ConfigurationStrategyImpl::GetStringOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_StringOptions;
}

Database::ConfigurationStrategyImpl::BooleanOption Database::ConfigurationStrategyImpl::GetBooleanOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_BooleanOptions;
}

Database::ConfigurationStrategyImpl::IntOption Database::ConfigurationStrategyImpl::GetIntOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_IntOptions;
}

Database::ConfigurationStrategyImpl::SSLOption Database::ConfigurationStrategyImpl::GetSSLOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_SSLOptions;
}

bool Database::ConfigurationStrategyImpl::IsUseSSL() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return !m_SSLOptions.empty();
}

Database::ConfigurationStrategyImpl::DBMapping Database::ConfigurationStrategyImpl::GetDBMapping() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_DBMapping;
}

std::string Database::ConfigurationStrategyImpl::GetDBName(int dbIndex) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto iter = m_DBMapping.find(dbIndex);
    if (iter != m_DBMapping.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的数据库索引。"s));
    }
}

bool Database::ConfigurationStrategyImpl::GetPooling() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_Pooling;
}

int Database::ConfigurationStrategyImpl::GetPoolMaxSize() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_PoolMaxSize;
}

int Database::ConfigurationStrategyImpl::GetPoolQueueTimeout() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_PoolQueueTimeout;
}

int Database::ConfigurationStrategyImpl::GetPoolMaxIdleTime() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_PoolMaxIdleTime;
}
