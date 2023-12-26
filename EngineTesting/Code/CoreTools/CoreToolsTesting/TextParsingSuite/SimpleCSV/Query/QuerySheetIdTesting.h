///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 10:44)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_ID_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_ID_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySheetIdTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySheetIdTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySheetIdTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void QuerySheetIdTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_ID_TESTING_H