///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:19)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TYPE_CONVERSION_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TYPE_CONVERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CSVTypeConversionTesting final : public UnitTest
    {
    public:
        using ClassType = CSVTypeConversionTesting;
        using ParentType = UnitTest;

    public:
        explicit CSVTypeConversionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CSVDataTypeTest();
        void CSVFormatTypeTest();
        void ActualTypeTest();
        void GetFunctionNameTest();
        void ValueTypeTest();
        void BaseReturnDescribeTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TYPE_CONVERSION_TESTING_H
