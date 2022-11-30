///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 10:53)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H

#include "FormatErrorMessageUseBufferTestingBase.h"

namespace System
{
    class FormatErrorMessageUseDllMoudleAndUseBufferTesting final : public FormatErrorMessageUseBufferTestingBase
    {
    public:
        using ClassType = FormatErrorMessageUseDllMoudleAndUseBufferTesting;
        using ParentType = FormatErrorMessageUseBufferTestingBase;

    public:
        explicit FormatErrorMessageUseDllMoudleAndUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatErrorMessageUseDllMoudleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule);
        void FormatComErrorMessageUseDllMoudleAndUseBufferTest(ConstDynamicLinkModule dynamicLinkModule);

        void FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError);
        void FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError);
        void FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError);
        void FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError);
        void FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError);
        void FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError); 
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_USE_BUFFER_TESTING_H