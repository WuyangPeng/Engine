/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:23)

#include "CoreTools/CoreToolsExport.h"

#include "CommandArgumentFactory.h"
#include "CommandArgumentPackage.h"
#include "CommandArgumentType.h"
#include "NoValueCommandArgument.h"
#include "NumberCommandArgument.h"
#include "StringCommandArgument.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using namespace std::literals;

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const std::string& arguments, const std::string& value)
{
    if (const CommandArgumentType valueType{ value }; valueType.IsDigit())
    {
        return make_shared<NumberCommandArgument>(index, arguments, value);
    }
    else if (valueType.IsString())
    {
        return make_shared<StringCommandArgument>(index, arguments, value);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("命令行参数无效！"s))
    }
}

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const std::string& arguments)
{
    return make_shared<NoValueCommandArgument>(index, arguments);
}
