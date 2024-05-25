/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:00)

#ifndef CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H
#define CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H

#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CallbackParametersTesting final : public UnitTest
    {
    public:
        using ClassType = CallbackParametersTesting;
        using ParentType = UnitTest;

    public:
        explicit CallbackParametersTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr bool value0{ true };
        static constexpr int8_t value1{ 2 };
        static constexpr uint8_t value2{ 3 };
        static constexpr int16_t value3{ 4 };
        static constexpr uint16_t value4{ 5 };
        static constexpr int value5{ 6 };
        static constexpr uint32_t value6{ 7 };
        static constexpr int64_t value7{ 8 };
        static constexpr uint64_t value8{ 9 };
        static constexpr float value9{ 10.0f };
        static constexpr double value10{ 11.0 };
        inline static const std::string value11{ "value11" };
        inline static const std::wstring value12{ L"value12" };
        inline static const System::String value13{ SYSTEM_TEXT("value13") };

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BuiltInTest();
        void ParametersInterfaceTest();
        void InvalidParametersTest();
        void InvalidTypeTest();

        void SetValueTest(CallbackParameters& callbackParameters);
        void GetValueTest(const CallbackParameters& callbackParameters);
        void ParametersInterface0Test(int testValue, const CallbackParameters& callbackParameters);
        void ParametersInterface1Test(int testValue, const CallbackParameters& callbackParameters);
        void ParametersInterface2Test(int testValue, const CallbackParameters& callbackParameters);
    };
}

#endif  // CORE_TOOLS_CLASS_INVARIANT_SUITE_CALLBACK_PARAMETERS_TESTING_H