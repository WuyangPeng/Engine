/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:30)

#include "CreateMutexTesting.h"
#include "System/Threading/Mutex.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::CreateMutexTesting::CreateMutexTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, CreateMutexTesting)

void System::CreateMutexTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::CreateMutexTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CreateMutexTest);
}

void System::CreateMutexTesting::CreateMutexTest()
{
    const auto mutexHandle = CreateSystemMutex(nullptr, false, nullptr);

    ASSERT_TRUE(IsSystemMutexValid(mutexHandle));

    ASSERT_NOT_THROW_EXCEPTION_1(CloseMutexTest, mutexHandle);
}
