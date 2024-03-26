/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H

#include "FormatMessageTestingBase.h"

namespace System
{
    class FormatErrorMessageTesting final : public FormatMessageTestingBase
    {
    public:
        using ClassType = FormatErrorMessageTesting;
        using ParentType = FormatMessageTestingBase;

    public:
        explicit FormatErrorMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatErrorMessageTest(WindowsHLocal errorMessage);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_TESTING_H