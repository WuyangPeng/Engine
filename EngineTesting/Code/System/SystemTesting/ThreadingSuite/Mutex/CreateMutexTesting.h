///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 10:27)

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