//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:43)

#include "Database/DatabaseExport.h"

#include "Session.h"
#include "Detail/SessionFactory.h"
#include "Detail/SessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Database::Session::Session(const ConfigurationStrategy& configurationStrategy)
    : m_Impl{ SessionFactory::Create(configurationStrategy) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Session::Session(const DatabaseObject& databaseObject)
    : m_Impl{ SessionFactory::Create(databaseObject) }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Session)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Session, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Session, GetSchemaContainer, Database::Session::SchemaContainer)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Session::SessionWeakPtr Database::Session::GetImplType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return m_Impl;
}
#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

Database::Session::ResultPtr Database::Session::ExecuteResult(const string& findStatement, int bindStatement)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, ExecuteResult, string, Database::Session::ResultPtr)

Database::Session::ResultPtr Database::Session::ExecuteResult(const string& findStatement, const string& bindStatement)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, Execute, string, void)

void Database::Session::Execute(const string& findStatement, const string& bindStatement)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Execute(findStatement, bindStatement);
}

void Database::Session::Execute(const string& findStatement, int bindStatement)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->Execute(findStatement, bindStatement);
}
