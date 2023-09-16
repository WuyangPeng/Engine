///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:52)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H

#include "FormatStringMessageUseArgumentTestingBase.h"

namespace System
{
    class FormatStringMessageUseVaListAndUseBufferTesting final : public FormatStringMessageUseArgumentTestingBase
    {
    public:
        using ClassType = FormatStringMessageUseVaListAndUseBufferTesting;
        using ParentType = FormatStringMessageUseArgumentTestingBase;

    public:
        explicit FormatStringMessageUseVaListAndUseBufferTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatStringMessageUseVaListAndUseBufferTest();
        void FormatStringMessageUseIndefiniteParameterTest(const TChar* message, ...);
        void FormatStringMessageUseArgumentsTest(const TChar* message, va_list vaArguments);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_STRING_MESSAGE_USE_VA_LIST_AND_USE_BUFFER_TESTING_H