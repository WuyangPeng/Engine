///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/02 19:02)

#ifndef SYSTEM_WINDOWS_SUITE_ENGINEERING_NUM_DIGITS_TESTING_H
#define SYSTEM_WINDOWS_SUITE_ENGINEERING_NUM_DIGITS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EngineeringNumDigitsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EngineeringNumDigitsTesting;
        using ParentType = UnitTest;

    public:
        explicit EngineeringNumDigitsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void NumDigitsTest();
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_ENGINEERING_NUM_DIGITS_TESTING_H