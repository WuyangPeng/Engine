/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.10 (2024/06/01 17:49)

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
        using Color = SimpleCSV::Color;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DefaultColorTest();
        void RgbColorTest();
        void RgbaColorTest();

        void DefaultColorGetHexTest(const Color& color0);
        void RgbColorGetHexTest(const Color& color0);
        void RgbaColorGetHexTest(const Color& color0);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLOR_TESTING_H
