/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.0 (2024/08/09 23:18)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_JSON_BASE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_JSON_BASE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class JsonBaseTesting final : public UnitTest
    {
    public:
        using ClassType = JsonBaseTesting;
        using ParentType = UnitTest;

    public:
        explicit JsonBaseTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() noexcept;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_JSON_BASE_TESTING_H
