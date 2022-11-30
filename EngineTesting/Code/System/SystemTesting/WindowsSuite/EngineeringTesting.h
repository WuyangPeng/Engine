///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 19:01)

#ifndef SYSTEM_WINDOWS_SUITE_ENGINEERING_TESTING_H
#define SYSTEM_WINDOWS_SUITE_ENGINEERING_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EngineeringTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EngineeringTesting;
        using ParentType = UnitTest;

    public:
        explicit EngineeringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SuffixTest();
        void OffsetTest() noexcept;
        void NumDigitsTest();
        void TypeDisplayerTest() noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_ENGINEERING_TESTING_H