///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/07 11:15)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHARED_STRINGS_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHARED_STRINGS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class QuerySharedStringsTesting final : public UnitTest
    {
    public:
        using ClassType = QuerySharedStringsTesting;
        using ParentType = UnitTest;

    public:
        explicit QuerySharedStringsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void QuerySharedStringsTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_QUERY_SHARED_STRINGS_TESTING_H
