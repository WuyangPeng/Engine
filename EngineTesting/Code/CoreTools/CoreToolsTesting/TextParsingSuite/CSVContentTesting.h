///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.4 (2023/03/10 10:16)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONTENT_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONTENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace CoreTools
{
    class CSVContentTesting final : public UnitTest
    {
    public:
        using ClassType = CSVContentTesting;
        using ParentType = UnitTest;
        using String = System::String;

    public:
        explicit CSVContentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateCSV();
        void CSVContentTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONTENT_TESTING_H
