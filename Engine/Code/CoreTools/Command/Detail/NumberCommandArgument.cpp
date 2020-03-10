// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:15)

#include "CoreTools/CoreToolsExport.h"

#include "NumberCommandArgument.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Helper/PragmaWarning/LexicalCast.h" 
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::NumberCommandArgument
	::NumberCommandArgument(int index, const string& name, const string& value)
	:ParentType{ index,name }, m_Value{ value }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::NumberCommandArgument
	::~NumberCommandArgument()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NumberCommandArgument)

int CoreTools::NumberCommandArgument
	::GetInteger() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::lexical_cast<int>(m_Value);
}

float CoreTools::NumberCommandArgument
	::GetFloat() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::lexical_cast<float>(m_Value);
}

double CoreTools::NumberCommandArgument
	::GetDouble() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return boost::lexical_cast<double>(m_Value);
}

const string CoreTools::NumberCommandArgument
	::GetString() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不是字符串！"));
}

bool CoreTools::NumberCommandArgument
	::IsInteger() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return true;
}

bool CoreTools::NumberCommandArgument
	::IsFloat() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return true;
}

bool CoreTools::NumberCommandArgument
	::IsDouble() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return true;
}

bool CoreTools::NumberCommandArgument
	::IsString() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

bool CoreTools::NumberCommandArgument
	::IsNoValue() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

CoreTools::NumberCommandArgument::CommandArgumentSharedPtr CoreTools::NumberCommandArgument
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return make_shared<NumberCommandArgument>(*this);
}

void CoreTools::NumberCommandArgument
	::AddArgumentValue(const string& value)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(value);

	THROW_EXCEPTION(SYSTEM_TEXT("NumberCommandArgument不能添加值！"));
}
