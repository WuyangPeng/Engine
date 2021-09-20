///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/27 13:20)

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
        void DoRunUnitTest() final;
        void MainTest();

        void GetTCREFullVersionTest() noexcept;
        void GetVersionTest();
        void GetTestingVersionTest();
        void IsAtLeastTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_VERSION_TESTING_H