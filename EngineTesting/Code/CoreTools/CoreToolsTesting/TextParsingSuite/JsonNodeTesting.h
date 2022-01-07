///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.6 (2021/11/10 20:41)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_JSON_NODE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_JSON_NODE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace CoreTools
{
    class JsonNodeTesting final : public UnitTest
    {
    public:
        using ClassType = JsonNodeTesting;
        using ParentType = UnitTest;

    public:
        explicit JsonNodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void JsonNodeTest();
        void JsonNodeContainerTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_NODE_TESTING_H
