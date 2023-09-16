///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 15:53)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_SN_PRINT_F_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_SN_PRINT_F_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class SnPrintFTesting final : public FormatStringTestingBase
    {
    public:
        using ClassType = SnPrintFTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit SnPrintFTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PrintTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_SN_PRINT_F_TESTING_H