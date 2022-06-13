///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 16:49)

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
