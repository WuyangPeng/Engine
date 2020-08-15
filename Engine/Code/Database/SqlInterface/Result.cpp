// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:34)

#include "Database/DatabaseExport.h"

#include "Result.h"
#include "Detail/ResultFactory.h"
#include "Detail/ResultImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::Result
	::Result(const ConfigurationStrategy& configurationStrategy)
	: m_Impl{ ResultFactory::Create(configurationStrategy) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Result
	::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult)
	: m_Impl{ ResultFactory::Create(configurationStrategy,mysqlxDocResult) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Result
::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
	: m_Impl{ ResultFactory::Create(configurationStrategy,mysqlxRowResult) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Result)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Result, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchOne, Database::Result::ResultRowPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchAll, Database::Result::ResultRowContainer)



