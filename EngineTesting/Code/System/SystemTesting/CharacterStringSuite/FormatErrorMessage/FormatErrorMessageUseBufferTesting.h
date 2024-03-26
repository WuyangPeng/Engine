/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H

#include "FormatErrorMessageUseBufferTestingBase.h"

namespace System
{
    class FormatErrorMessageUseBufferTesting final : public FormatErrorMessageUseBufferTestingBase
    {
    public:
        using ClassType = FormatErrorMessageUseBufferTesting;
        using ParentType = FormatErrorMessageUseBufferTestingBase;

    public:
        explicit FormatErrorMessageUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatErrorMessageUseBufferTest();
        void FormatComErrorMessageUseBufferTest();

        void FormatErrorMessageTest(WindowError windowError);
        void FormatErrorMessageSuccessTest(WindowError windowError);
        void FormatErrorMessageFailTest(WindowError windowError);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H