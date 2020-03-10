// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:07)

#include "Database/DatabaseExport.h"

#include "TableImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"

using std::string;
using std::initializer_list;

Database::TableImpl
	::TableImpl(const ConfigurationStrategy& configurationStrategy)
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::TableImpl
	::~TableImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, TableImpl)

Database::ConfigurationStrategy Database::TableImpl
	::GetConfigurationStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_1;

	return m_ConfigurationStrategy;
}

Database::TableImpl::ResultPtr Database::TableImpl
	::Select(std::initializer_list<string> selectStatement, const string& whereStatement, 
		     const string& orderByStatement, const BindStatementType& bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(selectStatement);
	SYSTEM_UNUSED_ARG(whereStatement);
	SYSTEM_UNUSED_ARG(orderByStatement);
	SYSTEM_UNUSED_ARG(bindStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("TableImplŒ¥ µœ÷Select"));
}

