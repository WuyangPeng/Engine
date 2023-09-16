///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 15:40)

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
        void DoRunUnitTest() override;
        void MainTest();

        void BoolConversionTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_BOOL_CONVERSION_TESTING_H