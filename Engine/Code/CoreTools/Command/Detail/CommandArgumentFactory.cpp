// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 11:13)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentFactory.h"
#include "CommandArgumentImpl.h"
#include "NumberCommandArgument.h"
#include "StringCommandArgument.h"
#include "NoValueCommandArgument.h"
#include "CommandArgumentType.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;
using std::make_shared;
using namespace std::literals;

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory
	::Create(int index, const string& arguments, const string& value)
{
	CommandArgumentType valueType{ value };

	if (valueType.IsDigit())
	{
		return make_shared<NumberCommandArgument>(index, arguments, value);
	}
	else if (valueType.IsString())
	{
		return make_shared<StringCommandArgument>(index, arguments, value);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("命令行参数无效！"s));
	}
}

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory
	::Create(int index, const string& arguments)
{
	return make_shared<NoValueCommandArgument>(index, arguments);
}
