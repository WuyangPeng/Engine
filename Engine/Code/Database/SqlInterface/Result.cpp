//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:42)

#include "Database/DatabaseExport.h"

#include "Result.h"
#include "Detail/ResultFactory.h"
#include "Detail/ResultImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::Result::Result(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ ResultFactory::Create(configurationStrategy) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Result::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultPtr& mysqlxDocResult)
    : m_Impl{ ResultFactory::Create(configurationStrategy, mysqlxDocResult) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Result::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultPtr& mysqlxRowResult)
    : m_Impl{ ResultFactory::Create(configurationStrategy, mysqlxRowResult) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Result)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Result, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchOne, Database::Result::ResultRowPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchAll, Database::Result::ResultRowContainer)
