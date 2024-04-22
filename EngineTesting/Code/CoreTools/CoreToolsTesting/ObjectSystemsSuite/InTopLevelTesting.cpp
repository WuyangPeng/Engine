/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/22 17:27)

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

    for (const auto& element : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(element));
    }

    for (auto& element : inTopLevel)
    {
        ASSERT_TRUE(inTopLevel.IsTopLevel(element));
    }
}
