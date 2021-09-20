///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/08 22:42)

#include "GetSystemInfoTesting.h"
#include "System/Windows/WindowsSystem.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::GetSystemInfoTesting::GetSystemInfoTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetSystemInfoTesting)

void System::GetSystemInfoTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetSystemInfoTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InfoTest);
}

void System::GetSystemInfoTesting::InfoTest()
{
    WindowsSystemInfo systemInfo{};
    GetWindowSystemInfo(systemInfo);

    ASSERT_LESS(0u, systemInfo.dwPageSize);
    ASSERT_UNEQUAL_NULL_PTR(systemInfo.lpMinimumApplicationAddress);
    ASSERT_UNEQUAL_NULL_PTR(systemInfo.lpMaximumApplicationAddress);
    ASSERT_LESS(0u, systemInfo.dwActiveProcessorMask);
    ASSERT_LESS(0u, systemInfo.dwNumberOfProcessors);
    ASSERT_LESS(0u, systemInfo.dwProcessorType);
    ASSERT_LESS(0u, systemInfo.dwAllocationGranularity);
    ASSERT_LESS(0, systemInfo.wProcessorLevel);
    ASSERT_LESS(0, systemInfo.wProcessorRevision);

    const auto numberOfProcessors = systemInfo.dwNumberOfProcessors;

    for (WindowsUChar processor{ 0 }; processor < numberOfProcessors; ++processor)
    {
        WindowsUChar nodeNumber{ 0 };
        ASSERT_TRUE(GetNumaProcessorNodeNumber(processor, &nodeNumber));
    }
}