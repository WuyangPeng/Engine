///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.4 (2022/11/29 0:17)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H

#include "FormatErrorMessageTestingBase.h"

namespace System
{
    class FormatErrorMessageUseDllMoudleAndLocalAllocTesting final : public FormatErrorMessageTestingBase
    {
    public:
        using ClassType = FormatErrorMessageUseDllMoudleAndLocalAllocTesting;
        using ParentType = FormatErrorMessageTestingBase;

    public:
        explicit FormatErrorMessageUseDllMoudleAndLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatErrorMessageUseDllMoudleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule);
        void FormatComErrorMessageUseDllMoudleAndLocalAllocTest(ConstDynamicLinkModule dynamicLinkModule);

        void FormatErrorMessageTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageSuccessTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageFailTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageUnknownTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageValidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageInvalidTest(ConstDynamicLinkModule dynamicLinkModule, WindowError windowError, WindowsHLocal& errorMessage);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_DLL_MOUDLE_AND_LOCAL_ALLOC_TESTING_H