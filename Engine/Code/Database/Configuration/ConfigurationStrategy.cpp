///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:28)

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
    DATABASE_SELF_CLASS_IS_VALID_1;
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
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ConfigurationStrategy)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetWrappersStrategy, Database::WrappersStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetIp, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetPort, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBHostName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBUserName, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBPassword, std::string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetFlagsOption, Database::ConfigurationStrategy::FlagsOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetStringOptions, Database::ConfigurationStrategy::StringOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetBooleanOptions, Database::ConfigurationStrategy::BooleanOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetIntOptions, Database::ConfigurationStrategy::IntOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetSSLOptions, Database::ConfigurationStrategy::SSLOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBMapping, Database::ConfigurationStrategy::DBMapping)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, IsUseSSL, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ConfigurationStrategy, GetDBName, int, std::string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetPooling, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetPoolMaxSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetPoolQueueTimeout, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetPoolMaxIdleTime, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, ConfigurationStrategy, GetThreadCount, int)