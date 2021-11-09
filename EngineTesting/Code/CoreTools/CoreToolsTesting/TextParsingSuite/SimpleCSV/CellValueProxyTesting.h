///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/08 11:23)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CellValueProxyTesting final : public UnitTest
    {
    public:
        using ClassType = CellValueProxyTesting;
        using ParentType = UnitTest;

    public:
        explicit CellValueProxyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CellValueProxyTypeTest();
        void CellValueProxySetTest();
        void CellValueTest();
        void CreateEmptyTest();
        void CellValueSetTest();
        void CellValueEqualTest();
        void CellTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CELL_VALUE_PROXY_TESTING_H
