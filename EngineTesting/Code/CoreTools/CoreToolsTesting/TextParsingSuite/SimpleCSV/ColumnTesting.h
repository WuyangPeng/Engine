///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/09 18:10)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ColumnTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_COLUMN_TESTING_H