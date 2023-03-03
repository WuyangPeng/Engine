///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/23 16:39)

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