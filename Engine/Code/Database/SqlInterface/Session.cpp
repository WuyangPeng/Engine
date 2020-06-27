// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.5 (2020/03/16 12:35)

#include "Database/DatabaseExport.h"

#include "Session.h"
#include "Detail/SessionFactory.h"
#include "Detail/SessionImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;

Database::Session
	::Session(const ConfigurationStrategy& configurationStrategy)
	: m_Impl{ SessionFactory::Create(configurationStrategy) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Session
	::Session(const DatabaseObject& databaseObject)
	: m_Impl{ SessionFactory::Create(databaseObject) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Session)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Session, GetConfigurationStrategy, Database::ConfigurationStrategy)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Session, GetSchemaContainer, Database::Session::SchemaContainer)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Session::SessionWeakPtr Database::Session
	::GetImplType() const
{
	DATABASE_CLASS_IS_VALID_CONST_1;

	return m_Impl;
}
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

Database::Session::ResultPtr Database::Session
	::ExecuteResult(const string& findStatement, int bindStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, ExecuteResult, string, Database::Session::ResultPtr)

Database::Session::ResultPtr Database::Session
	::ExecuteResult(const string& findStatement, const string& bindStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->ExecuteResult(findStatement, bindStatement);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Database, Session, Execute, string, void)

void Database::Session
	::Execute(const string& findStatement, const string& bindStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Execute(findStatement, bindStatement);
}

void Database::Session
	::Execute(const string& findStatement, int bindStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Execute(findStatement, bindStatement);
}

