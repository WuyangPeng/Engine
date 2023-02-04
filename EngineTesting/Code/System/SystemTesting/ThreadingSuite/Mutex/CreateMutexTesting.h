///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 10:00)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H

#include "MutexTestingBase.h"

namespace System
{
    class CreateMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = CreateMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit CreateMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreateMutexTest(); 
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_FLAGS_TESTING_H