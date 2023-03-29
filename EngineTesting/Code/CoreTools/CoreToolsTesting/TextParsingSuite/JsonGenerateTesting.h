///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/10 14:20)

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
        void DoRunUnitTest() override;
        void MainTest();

        void JsonGenerateHeadTest();
        void JsonGenerateDetailHeadTest();
        void JsonGenerateSourceTest();
        void JsonGenerateTotalTest();
        void JsonGenerateTotalRoadTest();
        void JsonGenerateTotalRunScenesTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_GENERATE_TESTING_H
