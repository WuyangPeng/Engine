// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:01)

#include "Database/DatabaseExport.h"

#include "CollectionImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"

using std::string;
 
Database::CollectionImpl
	::CollectionImpl(const ConfigurationStrategy& configurationStrategy)
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::CollectionImpl
	::~CollectionImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionImpl)

Database::CollectionImpl::ResultPtr Database::CollectionImpl
	::ExecuteDoc(const string& findStatement, const BindStatementType& bindStatement, int limitStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);
	SYSTEM_UNUSED_ARG(bindStatement);
	SYSTEM_UNUSED_ARG(limitStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("CollectionImplŒ¥ µœ÷Execute"));
}

Database::ConfigurationStrategy Database::CollectionImpl
	::GetConfigurationStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

