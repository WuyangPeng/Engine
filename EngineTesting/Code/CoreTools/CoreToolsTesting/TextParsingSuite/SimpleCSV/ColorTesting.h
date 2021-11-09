///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/07 12:02)

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
        void DoRunUnitTest() final;
        void MainTest();

        void DefaultColorTest();
        void RGBColorTest();
        void RGBAColorTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLOR_TESTING_H
