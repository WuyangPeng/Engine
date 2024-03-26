/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:32)

#include "LoadResourceTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadResourceTesting::LoadResourceTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceTesting)

void System::LoadResourceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);
}

void System::LoadResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadResourceTest);
}

void System::LoadResourceTesting::LoadResourceTest()
{
    for (const auto& [type, name] : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoLoadResourceTest, name, type);
    }
}

void System::LoadResourceTesting::DoLoadResourceTest(const DynamicLinkCharType* type, WindowsWord name)
{
    const auto resource = FindResourceInLibrary(GetDllModule(), type, MakeIntResource(name));

    ASSERT_UNEQUAL_NULL_PTR(resource);

    const auto global = GetResourceInLibrary(resource);

    ASSERT_NOT_THROW_EXCEPTION_1(LockResourceInLibraryTest, global);

    ASSERT_NOT_THROW_EXCEPTION_1(SizeofResourceInLibraryTest, resource);
}

System::DynamicLinkGlobal System::LoadResourceTesting::GetResourceInLibrary(DynamicLinkResource resource)
{
    const auto global = LoadResourceInLibrary(GetDllModule(), resource);

    ASSERT_UNEQUAL_NULL_PTR(global);

    return global;
}

void System::LoadResourceTesting::LockResourceInLibraryTest(DynamicLinkGlobal global)
{
    const auto resourceLock = LockResourceInLibrary(global);

    ASSERT_UNEQUAL_NULL_PTR(resourceLock);
}

void System::LoadResourceTesting::SizeofResourceInLibraryTest(DynamicLinkResource resource)
{
    const auto size = SizeofResourceInLibrary(GetDllModule(), resource);

    ASSERT_LESS(0u, size);
}
