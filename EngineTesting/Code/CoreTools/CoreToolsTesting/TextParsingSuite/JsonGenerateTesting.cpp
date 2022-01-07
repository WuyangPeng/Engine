///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.6 (2021/11/15 18:28)

#include "JsonGenerateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::vector;
using namespace std::literals;

CoreTools::JsonGenerateTesting::JsonGenerateTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, JsonGenerateTesting)

void CoreTools::JsonGenerateTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::JsonGenerateTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateDetailHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CSVGenerateTotalTest);
}

void CoreTools::JsonGenerateTesting::CSVGenerateHeadTest()
{
    JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/DungonMonsters.json"s) };

    JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Head };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::CSVGenerateDetailHeadTest()
{
    JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/DungonMonsters.json"s) };

    JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::DetailHead };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::CSVGenerateSourceTest()
{
    JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/DungonMonsters.json"s) };

    JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Source };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::CSVGenerateTotalTest()
{
    JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/DungonParts.json"s) };

    JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Total };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}
