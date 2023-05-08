///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/26 15:14)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ColumnTesting final : public UnitTest
    {
    public:
        using ClassType = ColumnTesting;
        using ParentType = UnitTest;

    public:
        explicit ColumnTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ColumnTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H