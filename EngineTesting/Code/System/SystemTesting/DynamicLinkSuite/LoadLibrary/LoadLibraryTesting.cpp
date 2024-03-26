/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:30)

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
    SYSTEM_SELF_CLASS_IS_VALID_1;
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
    const auto wsDll = DYNAMIC_LINK_TEXT("ws2_32"s);

    const auto module = LoadDynamicLibrary(wsDll.c_str(), LoadLibraryType::DoNotResolveDllReferences);

    ASSERT_UNEQUAL_NULL_PTR_FAILURE_THROW(module, "����ws2_32ʧ�ܡ�"s);

    ASSERT_TRUE(FreeDynamicLibrary(module));
}

void System::LoadLibraryTesting::LoadLibraryFailureTest()
{
    const auto errorDll = DYNAMIC_LINK_TEXT("error"s);

    const auto module = LoadDynamicLibrary(errorDll.c_str(), LoadLibraryType::DoNotResolveDllReferences);

    ASSERT_EQUAL_NULL_PTR(module);

    if (module != nullptr)
    {
        ASSERT_TRUE(FreeDynamicLibrary(module));
    }
}
