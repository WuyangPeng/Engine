///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/21 11:01)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�����в�����Ч��"s))
    }
}

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const std::string& arguments)
{
    return make_shared<NoValueCommandArgument>(index, arguments);
}
