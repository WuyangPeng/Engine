/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:30)

#include "GetProcessAddressTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::GetProcessAddressTesting::GetProcessAddressTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, GetProcessAddressTesting)

void System::GetProcessAddressTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::GetProcessAddressTesting::MainTest()
{
    const auto dynamicLinkModule = GetDynamicLibrary();

    ASSERT_NOT_THROW_EXCEPTION_1(GetProcAddressSucceedTest, dynamicLinkModule);
    ASSERT_NOT_THROW_EXCEPTION_1(GetProcAddressFailureTest, dynamicLinkModule);

    ASSERT_NOT_THROW_EXCEPTION_1(Destroy, dynamicLinkModule);
}

System::DynamicLinkModule System::GetProcessAddressTesting::GetDynamicLibrary()
{
    const auto kernel32Dll = DYNAMIC_LINK_TEXT("kernel32"s);

    return LoadDynamicLibrary(kernel32Dll.c_str(), LoadLibraryType::NoFlags);
}

void System::GetProcessAddressTesting::Destroy(DynamicLinkModule dynamicLinkModule)
{
    ASSERT_TRUE(FreeDynamicLibrary(dynamicLinkModule));
}

void System::GetProcessAddressTesting::GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule)
{
    const auto existProcessName = "GetLastError"s;

    const auto existProcess = GetProcessAddress(dynamicLinkModule, existProcessName.c_str());

    ASSERT_UNEQUAL_NULL_PTR(existProcess);
}

void System::GetProcessAddressTesting::GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule)
{
    const auto nonExistentProcessName = "GetLastErrorEx"s;

    const auto nonExistentProcess = GetProcessAddress(dynamicLinkModule, nonExistentProcessName.c_str());

    ASSERT_EQUAL_NULL_PTR(nonExistentProcess);
}
