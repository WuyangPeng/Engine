/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:27)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H

#include "CoreTools/TextParsing/CSV/CSVTotalGenerate.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <filesystem>

namespace CoreTools
{
    class CSVTotalGenerateTesting final : public UnitTest
    {
    public:
        using ClassType = CSVTotalGenerateTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVTotalGenerateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using String = System::String;
        using CSVHeadContainer = CSVTotalGenerate::CSVHeadContainer;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();
        void CSVTotalGenerateTest(CSVTotalGenerateType csvTotalGenerateType);
        NODISCARD CSVHeadContainer GetCSVHeadContainer() const;

    private:
        String directory;
        std::filesystem::path path;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TOTAL_GENERATE_TESTING_H
