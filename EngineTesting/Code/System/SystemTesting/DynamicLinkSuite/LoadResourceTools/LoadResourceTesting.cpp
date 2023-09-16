///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 17:08)

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
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadResourceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadTestingLibrary);

    ASSERT_NOT_THROW_EXCEPTION_0(LoadResourceTest);

    ASSERT_NOT_THROW_EXCEPTION_0(FreeTestingLibrary);

    // SystemWindowsTesting有dllModule为instance的测试。
}

void System::LoadResourceTesting::LoadResourceTest()
{
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoLoadResourceTest, typeName.second, typeName.first);
    }
}

void System::LoadResourceTesting::DoLoadResourceTest(const DynamicLinkCharType* type, WindowsWord name)
{
    const auto resource = FindResourceInLibrary(GetDllModule(), type, MakeIntreSource(name));

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
