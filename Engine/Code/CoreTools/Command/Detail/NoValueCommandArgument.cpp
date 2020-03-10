// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:14)

#include "CoreTools/CoreToolsExport.h"

#include "NoValueCommandArgument.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

CoreTools::NoValueCommandArgument
	::NoValueCommandArgument(int index, const string& name)
	:ParentType{ index, name }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::NoValueCommandArgument
	::~NoValueCommandArgument()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NoValueCommandArgument)

int CoreTools::NoValueCommandArgument
	::GetInteger() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument不是整数！"));
}

float CoreTools::NoValueCommandArgument
	::GetFloat() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument不是浮点数！"));
}

double CoreTools::NoValueCommandArgument
	::GetDouble() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument不是浮点数！"));
}

const string CoreTools::NoValueCommandArgument
	::GetString() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument不是字符串！"));
}

bool CoreTools::NoValueCommandArgument
	::IsInteger() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

bool CoreTools::NoValueCommandArgument
	::IsFloat() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

bool CoreTools::NoValueCommandArgument
	::IsDouble() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

bool CoreTools::NoValueCommandArgument
	::IsString() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return false;
}

bool CoreTools::NoValueCommandArgument
	::IsNoValue() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return true;
}

CoreTools::NoValueCommandArgument::CommandArgumentSharedPtr CoreTools::NoValueCommandArgument
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return make_shared<NoValueCommandArgument>(*this);
}

void CoreTools::NoValueCommandArgument
	::AddArgumentValue(const string& value)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	SYSTEM_UNUSED_ARG(value);

	THROW_EXCEPTION(SYSTEM_TEXT("NoValueCommandArgument没有值！"));
}

