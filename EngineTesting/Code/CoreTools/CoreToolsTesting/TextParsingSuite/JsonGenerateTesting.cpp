///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.7 (2023/04/26 16:06)

#include "JsonGenerateTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/JsonFlags.h"
#include "CoreTools/TextParsing/Json/JsonGenerate.h"
#include "CoreTools/TextParsing/Json/JsonHead.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

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
    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateDetailHeadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateSourceTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateTotalTest);

    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateTotalRoadTest);
    ASSERT_NOT_THROW_EXCEPTION_0(JsonGenerateTotalRunScenesTest);
}

void CoreTools::JsonGenerateTesting::JsonGenerateHeadTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/Monsters.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Head };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::JsonGenerateDetailHeadTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/Monsters.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::DetailHead };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::JsonGenerateSourceTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/Monsters.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Source };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::JsonGenerateTotalTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/Parts.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Total };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::JsonGenerateTotalRoadTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/Road.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Total };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}

void CoreTools::JsonGenerateTesting::JsonGenerateTotalRunScenesTest()
{
    const JsonHead jsonHead{ SYSTEM_TEXT("Resource/JsonConfigure/RunScenes.json"s) };

    const JsonGenerate jsonGenerate{ jsonHead, JsonGenerateType::Total };

    jsonGenerate.GenerateFile(SYSTEM_TEXT("Resource/JsonGenerate"s));
}
