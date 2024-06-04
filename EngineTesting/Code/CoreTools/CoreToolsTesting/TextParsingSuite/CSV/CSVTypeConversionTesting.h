/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 17:27)

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
        void DoRunUnitTest() override;
        void MainTest();

        void CSVDataTypeTest();
        void CSVFormatTypeTest();
        void ActualTypeTest();
        void GetFunctionNameTest();
        void ValueTypeTest();
        void BaseReturnDescribeTest();
        void GetAbbreviationTest();

        void GetTypeDescribe0Test();
        void GetTypeDescribe1Test();
        void GetDataType0Test();
        void GetDataType1Test();
        void GetTypeDescribe2Test();
        void GetFormatType0Test();
        void GetActualType0Test();
        void GetActualType1Test();
        void GetFunctionName0Test();
        void GetFunctionName1Test();
        void GetValueType0Test();
        void GetValueType1Test();
        void GetAbbreviation0Test();
        void GetAbbreviation1Test();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CSV_TYPE_CONVERSION_TESTING_H
