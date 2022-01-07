///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.6 (2021/11/20 13:00)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_DATA_TYPE_DESCRIBE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_DATA_TYPE_DESCRIBE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class DataTypeDescribeTesting final : public UnitTest
    {
    public:
        using ClassType = DataTypeDescribeTesting;
        using ParentType = UnitTest;

    public:
        explicit DataTypeDescribeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DataTypeDescribeTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_DATA_TYPE_DESCRIBE_TESTING_H
