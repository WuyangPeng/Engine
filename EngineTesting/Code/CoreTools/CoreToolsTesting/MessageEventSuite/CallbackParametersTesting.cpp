/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:01)

#include "CallbackParametersTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParametersDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Base/MathDetail.h"

CoreTools::CallbackParametersTesting::CallbackParametersTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CallbackParametersTesting)

void CoreTools::CallbackParametersTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CallbackParametersTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BuiltInTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParametersInterfaceTest);
    ASSERT_THROW_EXCEPTION_0(InvalidParametersTest);
    ASSERT_THROW_EXCEPTION_0(InvalidTypeTest);
}

void CoreTools::CallbackParametersTesting::BuiltInTest()
{
    CallbackParameters callbackParameters{ 0 };

    ASSERT_NOT_THROW_EXCEPTION_1(SetValueTest, callbackParameters);
    ASSERT_NOT_THROW_EXCEPTION_1(GetValueTest, callbackParameters);

    ASSERT_EQUAL(callbackParameters.GetContainerSize(), 14);
}

void CoreTools::CallbackParametersTesting::SetValueTest(CallbackParameters& callbackParameters)
{
    callbackParameters.SetValue(13, value13);
    callbackParameters.SetValue(12, value12);
    callbackParameters.SetValue(11, value11);
    callbackParameters.SetValue(10, value10);
    callbackParameters.SetValue(9, value9);
    callbackParameters.SetValue(8, value8);
    callbackParameters.SetValue(7, value7);
    callbackParameters.SetValue(6, value6);
    callbackParameters.SetValue(5, value5);
    callbackParameters.SetValue(4, value4);
    callbackParameters.SetValue(3, value3);
    callbackParameters.SetValue(2, value2);
    callbackParameters.SetValue(1, value1);
    callbackParameters.SetValue(0, value0);
}

void CoreTools::CallbackParametersTesting::GetValueTest(const CallbackParameters& callbackParameters)
{
    ASSERT_EQUAL(callbackParameters.GetBoolValue(0), value0);
    ASSERT_EQUAL(callbackParameters.GetInt8Value(1), value1);
    ASSERT_EQUAL(callbackParameters.GetUInt8Value(2), value2);
    ASSERT_EQUAL(callbackParameters.GetInt16Value(3), value3);
    ASSERT_EQUAL(callbackParameters.GetUInt16Value(4), value4);
    ASSERT_EQUAL(callbackParameters.GetInt32Value(5), value5);
    ASSERT_EQUAL(callbackParameters.GetUInt32Value(6), value6);
    ASSERT_EQUAL(callbackParameters.GetInt64Value(7), value7);
    ASSERT_EQUAL(callbackParameters.GetUInt64Value(8), value8);
    ASSERT_APPROXIMATE(callbackParameters.GetFloatValue(9), value9, Mathematics::MathF::GetZeroTolerance());
    ASSERT_APPROXIMATE(callbackParameters.GetDoubleValue(10), value10, Mathematics::MathD::GetZeroTolerance());
    ASSERT_EQUAL(callbackParameters.GetStringValue(11), value11);
    ASSERT_EQUAL(callbackParameters.GetWStringValue(12), value12);
    ASSERT_EQUAL(callbackParameters.GetTStringValue(13), value13);
}

void CoreTools::CallbackParametersTesting::ParametersInterfaceTest()
{
    constexpr auto testValue = 5;

    const auto pointer = Parameters::Create(testValue);
    CallbackParameters callbackParameters{ 0 };

    callbackParameters.SetValue(0, *pointer);

    ASSERT_NOT_THROW_EXCEPTION_2(ParametersInterface0Test, testValue, callbackParameters);

    pointer->SetValue(0);

    ASSERT_NOT_THROW_EXCEPTION_2(ParametersInterface1Test, testValue, callbackParameters);

    ASSERT_NOT_THROW_EXCEPTION_2(ParametersInterface2Test, testValue, callbackParameters);
}

void CoreTools::CallbackParametersTesting::ParametersInterface0Test(const int testValue, const CallbackParameters& callbackParameters)
{
    const auto cloneSmartPointer = boost::polymorphic_pointer_cast<const Parameters>(callbackParameters.GetParametersInterfaceValue(0));

    ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);
}

void CoreTools::CallbackParametersTesting::ParametersInterface1Test(const int testValue, const CallbackParameters& callbackParameters)
{
    const auto cloneSmartPointer = callbackParameters.GetParametersInterfacePolymorphicDowncast<const Parameters>(0);

    ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);
}

void CoreTools::CallbackParametersTesting::ParametersInterface2Test(const int testValue, const CallbackParameters& callbackParameters)
{
    const auto cloneSmartPointer = callbackParameters.GetParametersInterfacePolymorphicCast<const Parameters>(0);

    ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);
}

void CoreTools::CallbackParametersTesting::InvalidParametersTest()
{
    CallbackParameters callbackParameters{ 0 };

    constexpr auto setValue = true;

    callbackParameters.SetValue(1, setValue);

    std::ignore = callbackParameters.GetInt8Value(0);
}

void CoreTools::CallbackParametersTesting::InvalidTypeTest()
{
    CallbackParameters callbackParameters{ 0 };

    constexpr auto setValue = true;

    callbackParameters.SetValue(0, setValue);

    std::ignore = callbackParameters.GetInt8Value(0);
}
