///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.4 (2023/03/10 10:02)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CSV_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CSV_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BatchConversionCSVTesting final : public UnitTest
    {
    public:
        using ClassType = BatchConversionCSVTesting;
        using ParentType = UnitTest;

    public:
        explicit BatchConversionCSVTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BatchConversionCSVTest();
        void VerifyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CSV_TESTING_H
