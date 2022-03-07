///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:22)

#include "Database/DatabaseExport.h"

#include "Result.h"
#include "Detail/ResultFactory.h"
#include "Detail/ResultImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Database::Result::Result(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::Result::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxDocResultSharedPtr& mysqlxDocResult)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, mysqlxDocResult }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::Result::Result(const ConfigurationStrategy& configurationStrategy, const MysqlxRowResultSharedPtr& mysqlxRowResult)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy, mysqlxRowResult }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Result)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Result, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchOne, Database::Result::ResultRowPtr)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Result, FetchAll, Database::Result::ResultRowContainer)
