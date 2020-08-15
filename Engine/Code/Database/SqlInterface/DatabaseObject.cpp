// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:34)

#include "Database/DatabaseExport.h"

#include "DatabaseObject.h"
#include "Detail/DatabaseObjectFactory.h"
#include "Detail/DatabaseObjectImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::DatabaseObject
	::DatabaseObject(const ConfigurationStrategy& configurationStrategy)
	: m_Impl{ DatabaseObjectFactory::Create(configurationStrategy) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, DatabaseObject)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, DatabaseObject, GetConfigurationStrategy, Database::ConfigurationStrategy)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::DatabaseObject::DatabaseObjectWeakPtr Database::DatabaseObject
	::GetImplType() const noexcept
{
	DATABASE_CLASS_IS_VALID_CONST_1;

	return m_Impl;
}
#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)