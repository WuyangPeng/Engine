///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 17:03)

#ifndef CORE_TOOLS_BASE_SUITE_SINGLETON_TESTING_H
#define CORE_TOOLS_BASE_SUITE_SINGLETON_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SingletonTesting final : public UnitTest
    {
    public:
        using ClassType = SingletonTesting;
        using ParentType = UnitTest;

    public:
        explicit SingletonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SingletonPtrTest();
    };
}

#endif  // CORE_TOOLS_BASE_SUITE_SINGLETON_TESTING_H