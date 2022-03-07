///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:23)

#include "Database/DatabaseExport.h"

#include "Session.h"
#include "Detail/SessionFactory.h"
#include "Detail/SessionImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Database::Session::Session(const ConfigurationStrategy& configurationStrategy)
    : impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::Session::Session(const DatabaseObject& databaseObject)
    : impl{ CoreTools::ImplCreateUseFactory::Default, databaseObject }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Session)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Session, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Session, GetSchemaContainer, Database::Session::SchemaContainer)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Session, GetMysqlxSchema, Database::Session::MysqlxSchemaUniquePtr)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, Session, GetMysqlxSchema, int, Database::Session::MysqlxSchemaUniquePtr)

Database::Session::ResultPtr Database::Session::ExecuteResult(const string& findStatement, int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, ExecuteResult, string, Database::Session::ResultPtr)

Database::Session::ResultPtr Database::Session::ExecuteResult(const string& findStatement, const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, Execute, string, void)

void Database::Session::Execute(const string& findStatement, const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Execute(findStatement, bindStatement);
}

void Database::Session::Execute(const string& findStatement, int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Execute(findStatement, bindStatement);
}
