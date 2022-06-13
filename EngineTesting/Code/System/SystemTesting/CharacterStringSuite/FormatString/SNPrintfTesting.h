///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/15 13:08)

#ifndef SYSTEM_CHARACTER_STRING_SUITE_STRNG_PRINTF_TESTING_H
#define SYSTEM_CHARACTER_STRING_SUITE_STRNG_PRINTF_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

#include <vector>

namespace System
{
    class SNPrintfTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SNPrintfTesting;
        using ParentType = UnitTest;

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