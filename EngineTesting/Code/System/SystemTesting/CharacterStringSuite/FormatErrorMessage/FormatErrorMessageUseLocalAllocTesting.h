/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/11 14:02)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H

#include "FormatErrorMessageTestingBase.h"

namespace System
{
    class FormatErrorMessageUseLocalAllocTesting final : public FormatErrorMessageTestingBase
    {
    public:
        using ClassType = FormatErrorMessageUseLocalAllocTesting;
        using ParentType = FormatErrorMessageTestingBase;

    public:
        explicit FormatErrorMessageUseLocalAllocTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FormatErrorMessageUseLocalAllocTest();
        void FormatComErrorMessageUseLocalAllocTest();

        void FormatErrorMessageTest(WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageSuccessTest(WindowError windowError, WindowsHLocal& errorMessage);
        void FormatErrorMessageFailTest(WindowError windowError, WindowsHLocal& errorMessage);

        void DoFormatErrorMessageUseLocalAllocTest(WindowError flag);
        void DoFormatComErrorMessageUseLocalAllocTest(WindowError flag);
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_FORMAT_ERROR_MESSAGE_USE_LOCAL_ALLOC_TESTING_H