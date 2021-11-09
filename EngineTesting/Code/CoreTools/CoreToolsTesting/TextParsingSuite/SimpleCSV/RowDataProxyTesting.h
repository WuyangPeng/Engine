///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.4 (2021/10/11 12:54)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class RowDataProxyTesting final : public UnitTest
    {
    public:
        using ClassType = RowDataProxyTesting;
        using ParentType = UnitTest;

    public:
        explicit RowDataProxyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RowDataProxyTest();
        void CellValueContainerTest();
        void BoolContainerTest();
        void DeleteCellValuesTest();
        void PrependCellValueTest();
        void ClearTest();
        void DequeTest();
        void ListTest();
        void StringListTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_ROW_DATA_PROXY_TESTING_H