///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:17)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_NAME_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySheetNameTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySheetNameTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySheetNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void QuerySheetNameTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_NAME_TESTING_H
