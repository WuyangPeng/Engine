/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 10:25)

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