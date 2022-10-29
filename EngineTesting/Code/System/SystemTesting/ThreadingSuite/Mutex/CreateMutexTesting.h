///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:31)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateMutexTest();
        void CreateMutexUseNameTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H