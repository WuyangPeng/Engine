/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:27)

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
