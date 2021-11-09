///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.5 (2021/10/19 11:45)

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
        void DoRunUnitTest() final;
        void MainTest();

        void CreateCSV();
        void CSVContentTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_CONTENT_TESTING_H
