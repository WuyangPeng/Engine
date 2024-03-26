/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_PARAMETER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_PARAMETER_TESTING_H

#include "System/CharacterString/CharacterStringFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FormatErrorMessageParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatErrorMessageParameterTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatErrorMessageParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using FormatMessageOptionContainer = std::vector<FormatMessageOption>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ConstexprParameterTest() const noexcept;
        void ParameterTest();
        void DoParameterTest(FormatMessageOption formatMessageOption);

    private:
        FormatMessageOptionContainer formatMessageOptions;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_PARAMETER_TESTING_H