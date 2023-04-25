///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/24 15:19)

#include "OutTopLevelTesting.h"
#include "Detail/BoolObject.h"
#include "Detail/EnumObject.h"
#include "Detail/IntObject.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/NullObject.h"
#include "CoreTools/ObjectSystems/Object.h"
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
    auto outTopLevel = OutTopLevel::Create();

    ASSERT_EQUAL(outTopLevel.GetTopLevelSize(), 0);

    outTopLevel.Insert(std::make_shared<BoolObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<EnumObject>(DisableNotThrow::Disable));
    outTopLevel.Insert(std::make_shared<IntObject>(DisableNotThrow::Disable));

    ASSERT_EQUAL(outTopLevel.GetTopLevelSize(), 3);

    for (const auto& value : outTopLevel)
    {
        ASSERT_TRUE(outTopLevel.IsTopLevel(value));
    }

    for (auto& value : outTopLevel)
    {
        ASSERT_TRUE(outTopLevel.IsTopLevel(value));
    }
}
