/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:05)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    /// 这个测试不直接测试SheetBase，
    /// 而是通过Document类间接调用SheetBase的相关函数，
    /// 只测试基类SheetBase的函数。
    class SheetBaseTesting final : public UnitTest
    {
    public:
        using ClassType = SheetBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit SheetBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SheetBaseTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_SHEET_BASE_TESTING_H