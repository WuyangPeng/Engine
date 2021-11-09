///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/09/30 10:45)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELS_TARGET_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELS_TARGET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySheetRelsTargetTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySheetRelsTargetTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySheetRelsTargetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void QuerySheetRelsTargetTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHEET_RELS_TARGET_TESTING_H
