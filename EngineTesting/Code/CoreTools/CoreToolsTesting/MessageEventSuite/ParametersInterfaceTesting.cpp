///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 17:03)

#include "ParametersInterfaceTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"

#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/ParametersInterface.h"

using std::make_shared;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, ParametersInterface)

void CoreTools::ParametersInterfaceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CloneTest);
    ASSERT_NOT_THROW_EXCEPTION_0(SubclassTest);
}

void CoreTools::ParametersInterfaceTesting::CloneTest()
{
    TestingType parametersInterface;
    ParametersInterfaceSharedPtr smartPointer{ make_shared<TestingType>(parametersInterface) };
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
