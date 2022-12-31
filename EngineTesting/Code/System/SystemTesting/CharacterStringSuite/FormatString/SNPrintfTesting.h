///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/30 10:42)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRNG_PRINTF_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRNG_PRINTF_TESTING_H

#include "FormatStringTestingBase.h"

namespace System
{
    class SNPrintfTesting final : public FormatStringTestingBase
    {
    public:
        using ClassType = SNPrintfTesting;
        using ParentType = FormatStringTestingBase;

    public:
        explicit SNPrintfTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SnprintTest();
    };
}

#endif  // SYSTEM_CHARACTER_STRING_SUITE_STRNG_PRINTF_TESTING_H