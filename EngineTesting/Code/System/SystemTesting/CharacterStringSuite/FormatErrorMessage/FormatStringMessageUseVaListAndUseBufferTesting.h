///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:08)

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