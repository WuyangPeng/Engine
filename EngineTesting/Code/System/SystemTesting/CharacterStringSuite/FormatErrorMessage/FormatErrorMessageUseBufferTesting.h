///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/27 23:07)

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
        void DoRunUnitTest() final;
        void MainTest();

        void FormatErrorMessageUseBufferTest();
        void FormatComErrorMessageUseBufferTest();

        void FormatErrorMessageTest(WindowError windowError);
        void FormatErrorMessageSuccessTest(WindowError windowError);
        void FormatErrorMessageFailTest(WindowError windowError);
        void FormatErrorMessageUnknownTest(WindowError windowError);
        void FormatErrorMessageValidTest(WindowError windowError);
        void FormatErrorMessageInvalidTest(WindowError windowError);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_BUFFER_TESTING_H