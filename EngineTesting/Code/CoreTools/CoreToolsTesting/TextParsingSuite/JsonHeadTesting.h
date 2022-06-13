///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:22)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_JSON_HEAD_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_JSON_HEAD_TESTING_H

#include "CoreTools/TextParsing/TextParsingFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace CoreTools
{
    class JsonHeadTesting final : public UnitTest
    {
    public:
        using ClassType = JsonHeadTesting;
        using ParentType = UnitTest;

    public:
        explicit JsonHeadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void JsonHeadTest();
        void JsonHeadNodeTest(const JsonNode& jsonNode);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_HEAD_TESTING_H
