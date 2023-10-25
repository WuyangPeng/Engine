///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 11:29)

#ifndef CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H
#define CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TableTesting final : public UnitTest
    {
    public:
        using ClassType = TableTesting;
        using ParentType = UnitTest;

    public:
        explicit TableTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;
        void ForEachTest();
        void GetCoordinateTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H