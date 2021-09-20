///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/04/02 15:10)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FormatStringMessageUseVaListAndUseBufferTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatStringMessageUseVaListAndUseBufferTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatStringMessageUseVaListAndUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatStringUseVaListAndUseBufferTest();
        void ExecuteFormatStringUseVaListAndUseBufferTest(const TChar* message, ...);
        void DoExecuteFormatStringUseVaListAndUseBufferTest(const TChar* message, va_list arguments);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H