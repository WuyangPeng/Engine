// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:35)

#include "Database/DatabaseExport.h"

#include "Schema.h"
#include "Detail/SchemaFactory.h"
#include "Detail/SchemaImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::Schema
	::Schema(const Session& session)
	: m_Impl{ SchemaFactory::Create(session) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::Schema
	::Schema(const Session& session, int dbIndex)
	: m_Impl{ SchemaFactory::Create(session,dbIndex) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Schema)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Schema, GetConfigurationStrategy, Database::ConfigurationStrategy)

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::Schema::SchemaWeakPtr Database::Schema
	::GetImplType() const noexcept
{
	DATABASE_CLASS_IS_VALID_CONST_1;

	return m_Impl;
}

Database::Schema
	::Schema(const ConfigurationStrategy& configurationStrategy, const MysqlxSchema& mysqlxSchema)
	: m_Impl{ SchemaFactory::Create(configurationStrategy,mysqlxSchema) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)