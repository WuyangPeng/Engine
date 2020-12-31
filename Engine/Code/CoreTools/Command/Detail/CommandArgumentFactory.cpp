//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 16:40)

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
        THROW_EXCEPTION(SYSTEM_TEXT("�����в�����Ч��"s));
    }
}

CoreTools::CommandArgumentFactory::CommandArgumentSharedPtr CoreTools::CommandArgumentFactory::Create(int index, const string& arguments)
{
    return make_shared<NoValueCommandArgument>(index, arguments);
}
