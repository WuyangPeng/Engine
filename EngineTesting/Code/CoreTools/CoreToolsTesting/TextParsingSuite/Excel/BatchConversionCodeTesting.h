/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:23)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CODE_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CODE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BatchConversionCodeTesting final : public UnitTest
    {
    public:
        using ClassType = BatchConversionCodeTesting;
        using ParentType = UnitTest;

    public:
        explicit BatchConversionCodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void BatchConversionCodeTest();
        void VerifyTest();
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_BATCH_CONVERSION_CODE_TESTING_H