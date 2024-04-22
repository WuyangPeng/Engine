/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/19 10:27)

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
        void DoRunUnitTest() override;
        void MainTest();

        void IntegerTest();
        void StringTest();
        void OperatorTest();
        void ConstructorTest();
        void CompileErrorTest() noexcept;
        void ForEachTest();
        void GetCoordinateTest();
    };
}

#endif  // CORE_TOOLS_DATA_TYPES_SUITE_TABLE_TESTING_H