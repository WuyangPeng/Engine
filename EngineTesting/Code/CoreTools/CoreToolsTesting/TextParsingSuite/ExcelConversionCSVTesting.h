///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:25)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_EXCEL_CONVERSION_CSV_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_EXCEL_CONVERSION_CSV_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ExcelConversionCSVTesting final : public UnitTest
    {
    public:
        using ClassType = ExcelConversionCSVTesting;
        using ParentType = UnitTest;

    public:
        explicit ExcelConversionCSVTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ExcelConversionCSVTest();
        void ExcelConversionCSVUseOpenXLSXTest();
        void VerifyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_EXCEL_CONVERSION_CSV_TESTING_H
