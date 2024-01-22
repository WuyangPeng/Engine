/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:52)

#include "Database/DatabaseExport.h"

#include "ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::ConfigurationStrategyImpl::ConfigurationStrategyImpl(WrappersStrategy wrappersStrategy,
                                                               std::string ip,
                                                               int port,
                                                               std::string hostName,
                                                               std::string userName,
                                                               std::string password)
    : wrappersStrategyFlag{ wrappersStrategy },
      ip{ std::move(ip) },
      port{ port },
      hostName{ std::move(hostName) },
      userName{ std::move(userName) },
      password{ std::move(password) },
      pooling{ false },
      poolMaxSize{ 0 },
      poolQueueTimeout{ 0 },
      poolMaxIdleTime{ 0 },
      threadCount{ 1 },
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
                                                               std::string ip,
                                                               int port,
                                                               std::string hostName,
                                                               std::string userName,
                                                               std::string password,
                                                               bool pooling,
                                                               int poolMaxSize,
                                                               int poolQueueTimeout,
                                                               int poolMaxIdleTime,
                                                               int threadCount,
                                                               FlagsOption flagsOption,
                                                               StringOption stringOption,
                                                               BooleanOption booleanOption,
                                                               IntOption intOption,
                                                               SSLOption sslOption,
                                                               DBMapping dbMapping)
    : wrappersStrategyFlag{ wrappersStrategy },
      ip{ std::move(ip) },
      port{ port },
      hostName{ std::move(hostName) },
      userName{ std::move(userName) },
      password{ std::move(password) },
      pooling{ pooling },
      poolMaxSize{ poolMaxSize },
      poolQueueTimeout{ poolQueueTimeout },
      poolMaxIdleTime{ poolMaxIdleTime },
      threadCount{ threadCount },
      flagsOptions{ std::move(flagsOption) },
      stringOptions{ std::move(stringOption) },
      booleanOptions{ std::move(booleanOption) },
      intOptions{ std::move(intOption) },
      sslOptions{ std::move(sslOption) },
      dbMapping{ std::move(dbMapping) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ConfigurationStrategyImpl)

Database::WrappersStrategy Database::ConfigurationStrategyImpl::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return wrappersStrategyFlag;
}

std::string Database::ConfigurationStrategyImpl::GetIp() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return ip;
}

int Database::ConfigurationStrategyImpl::GetPort() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return port;
}

std::string Database::ConfigurationStrategyImpl::GetDBHostName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return hostName;
}

std::string Database::ConfigurationStrategyImpl::GetDBUserName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return userName;
}

std::string Database::ConfigurationStrategyImpl::GetDBPassword() const
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

    if (const auto iter = dbMapping.find(dbIndex);
        iter != dbMapping.cend())
    {
        return iter->second;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("未找到指定的数据库索引。"s))
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

int Database::ConfigurationStrategyImpl::GetThreadCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return threadCount;
}
