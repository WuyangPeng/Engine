///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:52)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H

#include "FormatStringMessageUseArgumentTestingBase.h"

namespace System
{
    class FormatStringMessageUseVaListAndLocalAllocTesting final : public FormatStringMessageUseArgumentTestingBase
    {
    public:
        using ClassType = FormatStringMessageUseVaListAndLocalAllocTesting;
        using ParentType = FormatStringMessageUseArgumentTestingBase;

    public:
        explicit FormatStringMessageUseVaListAndLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatStringMessageUseVaListAndLocalAllocTest();
        void FormatStringMessageUseIndefiniteParameterTest(const TChar* message, ...);
        void FormatStringMessageUseArgumentsTest(WindowsHLocal& resultMessage, const TChar* message, va_list vaArguments);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_LOCAL_ALLOC_TESTING_H