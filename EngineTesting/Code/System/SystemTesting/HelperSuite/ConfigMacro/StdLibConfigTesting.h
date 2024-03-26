/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/06 17:34)

#ifndef SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StdLibConfigTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StdLibConfigTesting;
        using ParentType = UnitTest;

    public:
        explicit StdLibConfigTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StdLibTest();
        void DinkumwareTest() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_STD_LIB_CONFIG_TESTING_H
