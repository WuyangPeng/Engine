///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:06)

#include "GetProcAddressTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::GetProcAddressTesting::GetProcAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetProcAddressTesting)

void System::GetProcAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetProcAddressTesting::MainTest()
{
    const auto dynamicLinkModule = GetDynamicLibrary();

    ASSERT_NOT_THROW_EXCEPTION_1(GetProcAddressSucceedTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(GetProcAddressFailureTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, dynamicLinkModule);
}

System::DynamicLinkModule System::GetProcAddressTesting::GetDynamicLibrary()
{
    const auto kernel32Dll = DYNAMIC_LINK_TEXT("kernel32"s);

    return LoadDynamicLibrary(kernel32Dll.c_str(), LoadLibraryType::NoFlags);
}

void System::GetProcAddressTesting::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}

void System::GetProcAddressTesting::GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule)
{
    const auto existProcessName = "GetLastError"s;

    const auto existProcess = GetProcessAddress(dynamicLinkModule, existProcessName.c_str());

    ASSERT_UNEQUAL_NULL_PTR(existProcess);
}

void System::GetProcAddressTesting::GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule)
{
    const auto nonExistentProcessName = "GetLastErrorEx"s;

    const auto nonExistentProcess = GetProcessAddress(dynamicLinkModule, nonExistentProcessName.c_str());

    ASSERT_EQUAL_NULL_PTR(nonExistentProcess);
}
