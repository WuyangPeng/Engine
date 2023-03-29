///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/10 10:16)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVGenerateTesting final : public UnitTest
    {
    public:
        using ClassType = CSVGenerateTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVGenerateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateCSV();
        void CSVGenerateBaseHeadTest();
        void CSVGenerateChildHeadTest();
        void CSVGenerateContainerHeadTest();
        void CSVGenerateContainerDetailHeadTest();
        void CSVGenerateBaseSourceTest();
        void CSVGenerateChildSourceTest();
        void CSVGenerateContainerSourceTest();
        void CSVGenerateTotalVectorTest();
        void CSVGenerateTotalTreeMapTest();
        void CSVGenerateTotalHashMapTest();
        void CSVGenerateTotalKeyTest();
        void CSVGenerateTotalEnumHeadTest();
        void CSVGenerateTotalEnumSourceTest();
        void CSVGenerateTotalEnumTotalTest();
        void CSVGenerateTotalUniqueTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_GENERATE_TESTING_H
