///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/25 11:29)

#include "LoadLibraryTesting.h"
#include "System/DynamicLink/Flags/LoadLibraryFlags.h"
#include "System/DynamicLink/LoadLibrary.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using namespace std::literals;

System::LoadLibraryTesting::LoadLibraryTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadLibraryTesting)

void System::LoadLibraryTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadLibraryTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadLibrarySucceedTest);
    ASSERT_NOT_THROW_EXCEPTION_0(LoadLibraryFailureTest);
}

void System::LoadLibraryTesting::LoadLibrarySucceedTest()
{
    const auto ws2_32Dll = DYNAMIC_LINK_TEXT("ws2_32"s);

    auto module = LoadDynamicLibrary(ws2_32Dll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(module, "����ws2_32ʧ�ܡ�"s);

    ASSERT_TRUE(FreeDynamicLibrary(module));
}

void System::LoadLibraryTesting::LoadLibraryFailureTest()
{
    const auto errorDll = DYNAMIC_LINK_TEXT("error"s);

    auto module = LoadDynamicLibrary(errorDll.c_str(), LoadLibraryType::DontResolveDllReferences);

    ASSERT_EQUAL_NULL_PTR(module);

    if (module != nullptr)
    {
        ASSERT_TRUE(FreeDynamicLibrary(module));
    }
}
