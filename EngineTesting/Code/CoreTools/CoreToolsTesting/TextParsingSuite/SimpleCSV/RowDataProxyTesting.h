///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:12)

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
        void DoRunUnitTest() override;
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