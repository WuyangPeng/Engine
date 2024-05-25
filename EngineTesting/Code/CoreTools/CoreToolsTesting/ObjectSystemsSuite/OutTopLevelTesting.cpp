/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/22 21:03)

#include "OutTopLevelTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/OutTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::OutTopLevelTesting::OutTopLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, OutTopLevelTesting)

void CoreTools::OutTopLevelTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::OutTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TopLevelTest);
}

void CoreTools::OutTopLevelTesting::TopLevelTest()
{
    const auto outTopLevel = GetOutTopLevel();

    ASSERT_EQUAL(outTopLevel.GetTopLevelSize(), 3);

    for (const auto& element : outTopLevel)
    {
        ASSERT_TRUE(outTopLevel.IsTopLevel(element));
    }

    for (auto& element : outTopLevel)
    {
        ASSERT_TRUE(outTopLevel.IsTopLevel(element));
    }
}

CoreTools::OutTopLevel CoreTools::OutTopLevelTesting::GetOutTopLevel()
{
    auto outTopLevel = OutTopLevel::Create();

    ASSERT_EQUAL(outTopLevel.GetTopLevelSize(), 0);

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    return outTopLevel;
}
