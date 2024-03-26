/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:04)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_NAME_TESTING_H

#include "MutexTestingBase.h"

namespace System
{
    class CreateMutexUseNameTesting final : public MutexTestingBase
    {
    public:
        using ClassType = CreateMutexUseNameTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit CreateMutexUseNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateMutexUseNameTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_MUTEX_USE_NAME_TESTING_H