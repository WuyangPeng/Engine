/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:02)

#include "ParametersInterfaceTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/ParametersInterface.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::ParametersInterfaceTesting::ParametersInterfaceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, ParametersInterfaceTesting)

void CoreTools::ParametersInterfaceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::ParametersInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CloneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SubclassTest);
}

void CoreTools::ParametersInterfaceTesting::CloneTest()
{
    ParametersInterface parametersInterface{};
    const auto pointer = make_shared<ParametersInterface>(parametersInterface);
    const auto clonePointer = pointer->Clone();

    ASSERT_UNEQUAL_NULL_PTR(pointer);
    ASSERT_UNEQUAL_NULL_PTR(clonePointer);
}

void CoreTools::ParametersInterfaceTesting::SubclassTest()
{
    auto testValue = 5;

    const auto pointer = std::make_shared<Parameters>(testValue);
    const auto clonePointer = pointer->Clone();

    ASSERT_UNEQUAL_NULL_PTR(pointer);
    ASSERT_UNEQUAL_NULL_PTR(clonePointer);

    ASSERT_EQUAL(pointer->GetValue(), testValue);

    pointer->SetValue(testValue + 1);

    ASSERT_EQUAL(pointer->GetValue(), testValue + 1);
}
