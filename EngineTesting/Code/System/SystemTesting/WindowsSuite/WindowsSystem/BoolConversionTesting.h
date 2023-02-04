///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 20:34)

#ifndef SYSTEM_WINDOWS_SUITE_BOOL_CONVERSION_TESTING_H
#define SYSTEM_WINDOWS_SUITE_BOOL_CONVERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class BoolConversionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = BoolConversionTesting;
        using ParentType = UnitTest;

    public:
        explicit BoolConversionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void BoolConversionTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_BOOL_CONVERSION_TESTING_H