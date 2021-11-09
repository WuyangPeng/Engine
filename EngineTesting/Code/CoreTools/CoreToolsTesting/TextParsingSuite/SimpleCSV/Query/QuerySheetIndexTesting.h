///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.4 (2021/09/30 10:45)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_INDEX_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_INDEX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySheetIndexTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySheetIndexTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySheetIndexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void QuerySheetIndexTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_INDEX_TESTING_H
