// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 09:46)

#include "Database/DatabaseExport.h" 

#include "ConfigurationStrategy.h"
#include "Detail/ConfigurationStrategyImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"

using std::string;  
using std::make_shared;
using std::vector;
using std::map;

Database::ConfigurationStrategy
	::ConfigurationStrategy(WrappersStrategy wrappersStrategy, const string& ip, uint32_t port,
		                    const string& hostName, const string& userName, const string& password)
	:m_Impl{ make_shared<ImplType>(wrappersStrategy,ip,port,hostName,userName,password)}
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::ConfigurationStrategy
	::ConfigurationStrategy(WrappersStrategy wrappersStrategy, const string& ip, uint32_t port, const string& hostName, 
		                    const string& userName, const string& password, bool pooling, int poolMaxSize,
		                    int poolQueueTimeout, int poolMaxIdleTime, const FlagsOption& flagsOption, const StringOption& stringOption,
		                    const BooleanOption& booleanOption, const IntOption& intOption, const SSLOption& sslOption, const DBMapping& dbMapping)
	:m_Impl{ make_shared<ImplType>(wrappersStrategy,ip,port,hostName,userName,password,pooling,poolMaxSize,poolQueueTimeout,poolMaxIdleTime,flagsOption,stringOption,booleanOption,intOption,sslOption,dbMapping)}
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, ConfigurationStrategy)  

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetWrappersStrategy,Database::WrappersStrategy)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetIP, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetPort, uint32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBHostName, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBUserName, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBPassword, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetFlagsOption, Database::ConfigurationStrategy::FlagsOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetStringOptions, Database::ConfigurationStrategy::StringOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetBooleanOptions, Database::ConfigurationStrategy::BooleanOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetIntOptions, Database::ConfigurationStrategy::IntOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetSSLOptions, Database::ConfigurationStrategy::SSLOption)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetDBMapping, Database::ConfigurationStrategy::DBMapping)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, IsUseSSL, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ConfigurationStrategy, GetDBName, int, string)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetPooling, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetPoolMaxSize, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetPoolQueueTimeout, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ConfigurationStrategy, GetPoolMaxIdleTime, int) 

