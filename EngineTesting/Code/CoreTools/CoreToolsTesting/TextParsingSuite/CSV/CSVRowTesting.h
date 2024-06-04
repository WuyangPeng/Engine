/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:27)

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

    public:
        explicit CSVRowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using String = System::String;
        using FileContent = std::vector<String>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();
        NODISCARD CSVHead ReadFile();
        NODISCARD static FileContent GetFileContent(const FileContent& content);

        void CSVRow0Test();
        void CSVRow1Test();

        void CSVRow0BaseTest(const CSVRow& csvRow);
        void CSVRow0VectorTest(const CSVRow& csvRow);
        void CSVRow0IntVectorTest(const CSVRow& csvRow);
        void CSVRow0ArrayTest(const CSVRow& csvRow);
        void CSVRow0VectorArrayTest(const CSVRow& csvRow);
        void CSVRow0IntVectorArrayTest(const CSVRow& csvRow);
        void CSVRow0StringArrayTest(const CSVRow& csvRow);

        void CSVRow1BaseTest(const CSVRow& csvRow);
        void CSVRow1VectorTest(const CSVRow& csvRow);
        void CSVRow1IntVectorTest(const CSVRow& csvRow);
        void CSVRow1ArrayTest(const CSVRow& csvRow);
        void CSVRow1VectorArrayTest(const CSVRow& csvRow);
        void CSVRow1IntVectorArrayTest(const CSVRow& csvRow);
        void CSVRow1StringArrayTest(const CSVRow& csvRow);

    private:
        String rowContent0;
        String rowContent1;
        String csvFileName;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_ROW_TESTING_H
