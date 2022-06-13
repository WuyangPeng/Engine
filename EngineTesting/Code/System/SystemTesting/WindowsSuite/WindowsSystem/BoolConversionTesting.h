///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 15:44)

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