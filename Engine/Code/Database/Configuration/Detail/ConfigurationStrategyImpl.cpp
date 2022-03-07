///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 11:22)

#include "Database/DatabaseExport.h"

#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::map;
using std::string;
using std::vector;

Database::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                                               const string& ip,
                                                               int port,
                                                               const string& hostName,
                                                               const string& userName,
                                                               const string& password)
    : wrappersStrategyFlag{ wrappersStrategy },
      ip{ ip },
      port{ port },
      hostName{ hostName },
      userName{ userName },
      password{ password },
      pooling{ false },
      poolMaxSize{ 0 },
      poolQueueTimeout{ 0 },
      poolMaxIdleTime{ 0 },
      flagsOptions{},
      stringOptions{},
      booleanOptions{},
      intOptions{},
      sslOptions{},
      dbMapping{}
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                                               const string& ip,
                                                               int port,
                                                               const string& hostName,
                                                               const string& userName,
                                                               const string& password,
                                                               bool pooling,
                                                               int poolMaxSize,
                                                               int poolQueueTimeout,
                                                               int poolMaxIdleTime,
                                                               const FlagsOption& flagsOption,
                                                               const StringOption& stringOption,
                                                               const BooleanOption& booleanOption,
                                                               const IntOption& intOption,
                                                               const SSLOption& sslOption,
                                                               const DBMapping& dbMapping)
    : wrappersStrategyFlag{ wrappersStrategy },
      ip{ ip },
      port{ port },
      hostName{ hostName },
      userName{ userName },
      password{ password },
      pooling{ pooling },
      poolMaxSize{ poolMaxSize },
      poolQueueTimeout{ poolQueueTimeout },
      poolMaxIdleTime{ poolMaxIdleTime },
      flagsOptions{ flagsOption },
      stringOptions{ stringOption },
      booleanOptions{ booleanOption },
      intOptions{ intOption },
      sslOptions{ sslOption },
      dbMapping{ dbMapping }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ConfigurationStrategyImpl)

Database::WrappersStrategy Database::ConfigurationStrategyImpl::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return wrappersStrategyFlag;
}

string Database::ConfigurationStrategyImpl::GetIP() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return ip;
}

int Database::ConfigurationStrategyImpl::GetPort() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return port;
}

string Database::ConfigurationStrategyImpl::GetDBHostName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return hostName;
}

string Database::ConfigurationStrategyImpl::GetDBUserName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return userName;
}

string Database::ConfigurationStrategyImpl::GetDBPassword() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return password;
}

Database::ConfigurationStrategyImpl::FlagsOption Database::ConfigurationStrategyImpl::GetFlagsOption() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return flagsOptions;
}

Database::ConfigurationStrategyImpl::StringOption Database::ConfigurationStrategyImpl::GetStringOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return stringOptions;
}

Database::ConfigurationStrategyImpl::BooleanOption Database::ConfigurationStrategyImpl::GetBooleanOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return booleanOptions;
}

Database::ConfigurationStrategyImpl::IntOption Database::ConfigurationStrategyImpl::GetIntOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return intOptions;
}

Database::ConfigurationStrategyImpl::SSLOption Database::ConfigurationStrategyImpl::GetSSLOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return sslOptions;
}

bool Database::ConfigurationStrategyImpl::IsUseSSL() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return !sslOptions.empty();
}

Database::ConfigurationStrategyImpl::DBMapping Database::ConfigurationStrategyImpl::GetDBMapping() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return dbMapping;
}

std::string Database::ConfigurationStrategyImpl::GetDBName(int dbIndex) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto iter = dbMapping.find(dbIndex);
    if (iter != dbMapping.cend())
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

    return pooling;
}

int Database::ConfigurationStrategyImpl::GetPoolMaxSize() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return poolMaxSize;
}

int Database::ConfigurationStrategyImpl::GetPoolQueueTimeout() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return poolQueueTimeout;
}

int Database::ConfigurationStrategyImpl::GetPoolMaxIdleTime() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return poolMaxIdleTime;
}
