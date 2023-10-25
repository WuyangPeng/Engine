///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:17)

#include "InTopLevelTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/InTopLevel.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::InTopLevelTesting::InTopLevelTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, InTopLevelTesting)

void CoreTools::InTopLevelTesting::DoRunUnitTest()
{
    InitTerm::ExecuteInitializer();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    InitTerm::ExecuteTerminator();
}

void CoreTools::InTopLevelTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BasisTest);
}

void CoreTools::InTopLevelTesting::BasisTest()
{
    auto inTopLevel = InTopLevel::Create();

    ASSERT_EQUAL(inTopLevel.GetTopLevelSize(), 0);

    inTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    inTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    inTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    ASSERT_EQUAL(inTopLevel.GetTopLevelSize(), 3);

    for (const auto& value : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(value));
    }

    for (auto& value : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(value));
    }
}
