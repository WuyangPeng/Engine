// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:01)

#include "CallbackParametersTesting.h"
#include "Detail/Parameters.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "CoreTools/MessageEvent/CallbackParametersDetail.h"

using std::make_shared;
using std::string;
using std::wstring;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, CallbackParameters)

void CoreTools::CallbackParametersTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BuiltInTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ParametersInterfaceTest);
    ASSERT_THROW_EXCEPTION_0(InvalidParametersTest);
    ASSERT_THROW_EXCEPTION_0(InvalidTypeTest);
}

void CoreTools::CallbackParametersTesting ::BuiltInTest()
{
    TestingType callbackParameters{ 0 };

    constexpr bool firstValue{ true };
    constexpr int8_t secondValue{ 2 };
    constexpr uint8_t thirdValue{ 3 };
    constexpr int16_t fourthValue{ 4 };
    constexpr uint16_t fifthValue{ 5 };
    constexpr int sixthValue{ 6 };
    constexpr uint32_t seventhValue{ 7 };
    constexpr int64_t eighthValue{ 8 };
    constexpr uint64_t ninthValue{ 9 };
    constexpr float tenthValue{ 10.0f };
    constexpr double eleventhValue{ 11.0 };
    string twelfthValue{ "twelfthValue" };
    wstring thirteenthValue{ L"thirteenthValue" };
    System::String fourteenthValue{ SYSTEM_TEXT("fourteenthValue") };

    callbackParameters.SetValue(13, fourteenthValue);
    callbackParameters.SetValue(12, thirteenthValue);
    callbackParameters.SetValue(11, twelfthValue);
    callbackParameters.SetValue(10, eleventhValue);
    callbackParameters.SetValue(9, tenthValue);
    callbackParameters.SetValue(8, ninthValue);
    callbackParameters.SetValue(7, eighthValue);
    callbackParameters.SetValue(6, seventhValue);
    callbackParameters.SetValue(5, sixthValue);
    callbackParameters.SetValue(4, fifthValue);
    callbackParameters.SetValue(3, fourthValue);
    callbackParameters.SetValue(2, thirdValue);
    callbackParameters.SetValue(1, secondValue);
    callbackParameters.SetValue(0, firstValue);

    ASSERT_EQUAL(callbackParameters.GetBoolValue(0), firstValue);
    ASSERT_EQUAL(callbackParameters.GetInt8Value(1), secondValue);
    ASSERT_EQUAL(callbackParameters.GetUInt8Value(2), thirdValue);
    ASSERT_EQUAL(callbackParameters.GetInt16Value(3), fourthValue);
    ASSERT_EQUAL(callbackParameters.GetUInt16Value(4), fifthValue);
    ASSERT_EQUAL(callbackParameters.GetInt32Value(5), sixthValue);
    ASSERT_EQUAL(callbackParameters.GetUInt32Value(6), seventhValue);
    ASSERT_EQUAL(callbackParameters.GetInt64Value(7), eighthValue);
    ASSERT_EQUAL(callbackParameters.GetUInt64Value(8), ninthValue);
    ASSERT_APPROXIMATE(callbackParameters.GetFloatValue(9), tenthValue, 1e-6f);
    ASSERT_APPROXIMATE(callbackParameters.GetDoubleValue(10), eleventhValue, 1e-8);
    ASSERT_EQUAL(callbackParameters.GetStringValue(11), twelfthValue);
    ASSERT_EQUAL(callbackParameters.GetWStringValue(12), thirteenthValue);
    ASSERT_EQUAL(callbackParameters.GetTStringValue(13), fourteenthValue);

    ASSERT_EQUAL(callbackParameters.GetContainerSize(), 14);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
void CoreTools::CallbackParametersTesting ::ParametersInterfaceTest()
{
    auto testValue = 5;

    ParametersSharedPtr smartPointer{ make_shared<Parameters>(testValue) };
    TestingType callbackParameters{ 0 };

    callbackParameters.SetValue(0, *smartPointer);

    //  auto cloneSmartPointer = PolymorphicSharedPtrDowncast<const Parameters>(callbackParameters.GetParametersInterfaceValue(0));

    // ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);

    smartPointer->SetValue(0);

    auto cloneSmartPointer = callbackParameters.GetParametersInterfacePolymorphicDowncast<const Parameters>(0);

    ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);

    cloneSmartPointer = callbackParameters.GetParametersInterfacePolymorphicCast<const Parameters>(0);

    ASSERT_EQUAL(cloneSmartPointer->GetValue(), testValue);
}
#include STSTEM_WARNING_POP
void CoreTools::CallbackParametersTesting ::InvalidParametersTest()
{
    TestingType callbackParameters{ 0 };

    constexpr bool firstValue{ true };

    callbackParameters.SetValue(1, firstValue);

    [[maybe_unused]] const auto value = callbackParameters.GetInt8Value(0);
}

void CoreTools::CallbackParametersTesting ::InvalidTypeTest()
{
    TestingType callbackParameters{ 0 };

    constexpr bool firstValue{ true };

    callbackParameters.SetValue(0, firstValue);

    [[maybe_unused]] const auto value = callbackParameters.GetInt8Value(0);
}
