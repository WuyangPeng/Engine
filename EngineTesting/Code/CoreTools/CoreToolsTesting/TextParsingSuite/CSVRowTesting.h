///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.5 (2021/10/18 17:06)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H

#include "CoreTools/TextParsing/CSV/CSVHead.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

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
        void DoRunUnitTest() final;
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
