///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:21)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_JSON_GENERATE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_JSON_GENERATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class JsonGenerateTesting final : public UnitTest
    {
    public:
        using ClassType = JsonGenerateTesting;
        using ParentType = UnitTest;

    public:
        explicit JsonGenerateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CSVGenerateHeadTest();
        void CSVGenerateDetailHeadTest();
        void CSVGenerateSourceTest();
        void CSVGenerateTotalTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_GENERATE_TESTING_H
