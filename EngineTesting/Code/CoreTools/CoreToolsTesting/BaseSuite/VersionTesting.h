///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 16:39)

#ifndef CORE_TOOLS_BASE_SUITE_VERSION_TESTING_H
#define CORE_TOOLS_BASE_SUITE_VERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class VersionTesting final : public UnitTest
    {
    public:
        using ClassType = VersionTesting;
        using ParentType = UnitTest;

    public:
        explicit VersionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetTCREFullVersionTest() noexcept;
        void GetVersionTest();
        void GetTestingVersionTest();
        void IsAtLeastTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_VERSION_TESTING_H