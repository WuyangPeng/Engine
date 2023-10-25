///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 10:45)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COLOR_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COLOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ColorTesting final : public UnitTest
    {
    public:
        using ClassType = ColorTesting;
        using ParentType = UnitTest;

    public:
        explicit ColorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultColorTest();
        void RgbColorTest();
        void RgbaColorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLOR_TESTING_H
