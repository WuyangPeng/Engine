///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:02)

#ifndef CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H
#define CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StaticSingletonTesting final : public UnitTest
    {
    public:
        using ClassType = StaticSingletonTesting;
        using ParentType = UnitTest;

    public:
        explicit StaticSingletonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StaticSingletonTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_STATIC_SINGLETON_TESTING_H