///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:11)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H

#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVRowTesting final : public UnitTest
    {
    public:
        using ClassType = CSVRowTesting;
        using String = System::String;
        using ParentType = UnitTest;

    public:
        explicit CSVRowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();
        NODISCARD CSVHead ReadFile();
        void CSVRow0Test();
        void CSVRow1Test();

    private:
        String rowContent0;
        String rowContent1;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H
