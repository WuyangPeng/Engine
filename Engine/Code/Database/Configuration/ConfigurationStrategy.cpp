///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:55)

#include "Database/DatabaseExport.h"

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                                                       const std::string& ip,
                                                       int port,
                                                       const std::string& hostName,
                                                       const std::string& userName,
                                                       const std::string& password)
    : impl{ wrappersStrategy, ip, port, hostName, userName, password }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ConfigurationStrategy::ConfigurationStrategy(WrappersStrategy wrappersStrategy,
                                                       const std::string& ip,
                                                       int port,
                                                       const std::string& hostName,
                                                       const std::string& userName,
                                                       const std::string& password,
                                                       bool pooling,
                                                       int poolMaxSize,
                                                       int poolQueueTimeout,
                                                       int poolMaxIdleTime,
                                                       int threadCount,
                                                       const FlagsOption& flagsOption,
                                                       const StringOption& stringOption,
                                                       const BooleanOption& booleanOption,
                                                       const IntOption& intOption,
                                                       const SSLOption& sslOption,
                                                       const DBMapping& dbMapping)
    : impl{ wrappersStrategy, ip, port, hostName, userName, password, pooling, poolMaxSize, poolQueueTimeout, poolMaxIdleTime, threadCount, flagsOption, stringOption, booleanOption, intOption, sslOption, dbMapping }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ConfigurationStrategy)

Database::WrappersStrategy Database::ConfigurationStrategy::GetWrappersStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetWrappersStrategy();
}

std::string Database::ConfigurationStrategy::GetIp() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetIp();
}

int Database::ConfigurationStrategy::GetPort() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetPort();
}

std::string Database::ConfigurationStrategy::GetDBHostName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDBHostName();
}

std::string Database::ConfigurationStrategy::GetDBUserName() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDBUserName();
}

std::string Database::ConfigurationStrategy::GetDBPassword() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDBPassword();
}

Database::ConfigurationStrategy::FlagsOption Database::ConfigurationStrategy::GetFlagsOption() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetFlagsOption();
}

Database::ConfigurationStrategy::StringOption Database::ConfigurationStrategy::GetStringOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetStringOptions();
}

Database::ConfigurationStrategy::BooleanOption Database::ConfigurationStrategy::GetBooleanOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetBooleanOptions();
}

Database::ConfigurationStrategy::IntOption Database::ConfigurationStrategy::GetIntOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetIntOptions();
}

Database::ConfigurationStrategy::SSLOption Database::ConfigurationStrategy::GetSSLOptions() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetSSLOptions();
}

Database::ConfigurationStrategy::DBMapping Database::ConfigurationStrategy::GetDBMapping() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDBMapping();
}

bool Database::ConfigurationStrategy::IsUseSSL() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->IsUseSSL();
}

std::string Database::ConfigurationStrategy::GetDBName(int dbIndex) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDBName(dbIndex);
}

bool Database::ConfigurationStrategy::GetPooling() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetPooling();
}

int Database::ConfigurationStrategy::GetPoolMaxSize() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetPoolMaxSize();
}

int Database::ConfigurationStrategy::GetPoolQueueTimeout() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetPoolQueueTimeout();
}

int Database::ConfigurationStrategy::GetPoolMaxIdleTime() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetPoolMaxIdleTime();
}

int Database::ConfigurationStrategy::GetThreadCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetThreadCount();
}
