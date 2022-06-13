///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:14)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELSID_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELSID_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySheetRelsIDTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySheetRelsIDTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySheetRelsIDTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void QuerySheetRelsIDTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELSID_TESTING_H
