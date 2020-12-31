//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 16:40)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentFactory.h"
#include "CommandArgumentImpl.h"
#include "CommandArgumentType.h"
#include "NoValueCommandArgument.h"
#include "NumberCommandArgument.h"
#include "StringCommandArgument.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;
using namespace std::literals;

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const string& arguments, const string& value)
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

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const string& arguments)
{
    return make_shared<NoValueCommandArgument>(index, arguments);
}
