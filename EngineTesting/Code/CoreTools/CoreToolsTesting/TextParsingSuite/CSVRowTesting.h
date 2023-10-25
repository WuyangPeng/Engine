///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:25)

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
        using ParentType = UnitTest;

        using String = System::String;

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
