///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/04/02 14:33)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class FormatStringMessageUseVaListAndLocalAllocTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FormatStringMessageUseVaListAndLocalAllocTesting;
        using ParentType = UnitTest;

    public:
        explicit FormatStringMessageUseVaListAndLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FormatStringUseVaListAndLocalAllocTest();
        void ExecuteFormatStringUseVaListAndLocalAllocTest(const TChar* message, ...);
        void DoExecuteFormatStringUseVaListAndLocalAllocTest(const TChar* message, va_list arguments);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H