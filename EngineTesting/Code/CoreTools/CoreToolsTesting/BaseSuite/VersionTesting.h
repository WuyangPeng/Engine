/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 14:38)

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

        void GetTcreFullVersionTest() noexcept;
        void GetVersionTest();
        void GetTestingVersionTest();
        void IsAtLeastTest();
        void GetTestingVersionAtLeastTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_VERSION_TESTING_H