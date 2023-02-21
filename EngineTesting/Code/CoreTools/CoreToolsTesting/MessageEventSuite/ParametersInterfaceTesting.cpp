///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 17:03)

#include "ParametersInterfaceTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/ParametersInterface.h"

using std::make_shared;

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
    ParametersInterface parametersInterface;
    ParametersInterfaceSharedPtr smartPointer{ make_shared<ParametersInterface>(parametersInterface) };
    auto cloneSmartPointer = smartPointer->Clone();

    ASSERT_UNEQUAL_NULL_PTR(smartPointer);
    ASSERT_UNEQUAL_NULL_PTR(cloneSmartPointer);
}

void CoreTools::ParametersInterfaceTesting::SubclassTest()
{
    auto testValue = 5;

    ParametersSharedPtr smartPointer{ make_shared<Parameters>(testValue) };
    auto cloneSmartPointer = smartPointer->Clone();

    ASSERT_UNEQUAL_NULL_PTR(smartPointer);
    ASSERT_UNEQUAL_NULL_PTR(cloneSmartPointer);

    ASSERT_EQUAL(smartPointer->GetValue(), testValue);

    smartPointer->SetValue(testValue + 1);

    ASSERT_EQUAL(smartPointer->GetValue(), testValue + 1);
}
