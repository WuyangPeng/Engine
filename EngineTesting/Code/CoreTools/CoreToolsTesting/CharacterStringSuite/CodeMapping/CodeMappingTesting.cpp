/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 14:59)

#include "CodeMappingTesting.h"
#include "CoreTools/CharacterString/CodeMapping.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace CoreTools
{
    const auto key = SYSTEM_TEXT("key");
    const auto element = SYSTEM_TEXT("element");
}

CoreTools::CodeMappingTesting::CodeMappingTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CodeMappingTesting)

void CoreTools::CodeMappingTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CodeMappingTesting::MainTest()
{
    ASSERT_THROW_EXCEPTION_0(GetElementFailTest);
    ASSERT_NOT_THROW_EXCEPTION_0(InsertSuccessTest);
    ASSERT_THROW_EXCEPTION_0(InsertFailTest);
}

void CoreTools::CodeMappingTesting::GetElementFailTest()
{
    const auto codeMapping = CodeMapping::Create();

    const auto result = codeMapping.GetElement(SYSTEM_TEXT("nonExistentKey"));

    ASSERT_FALSE(result.empty() || !result.empty());
}

void CoreTools::CodeMappingTesting::InsertSuccessTest()
{
    auto codeMapping = CodeMapping::Create();

    codeMapping.Insert(key, element);

    ASSERT_EQUAL(codeMapping.GetElement(key), element);
}

void CoreTools::CodeMappingTesting::InsertFailTest()
{
    auto codeMapping = CodeMapping::Create();

    codeMapping.Insert(key, element);
    codeMapping.Insert(key, element);
}
