/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:03)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_TESTING_H

#include "MutexTestingBase.h"

namespace System
{
    class CreateDefaultMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = CreateDefaultMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit CreateDefaultMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateDefaultMutexTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_TESTING_H