///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 23:21)

#include "LoadResourceWindowsTesting.h"
#include "System/DynamicLink/LoadResourceTools.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::LoadResourceWindowsTesting::LoadResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance)
    : ParentType{ stream, instance }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, LoadResourceWindowsTesting)

void System::LoadResourceWindowsTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::LoadResourceWindowsTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LoadResourceTest);
}

void System::LoadResourceWindowsTesting::LoadResourceTest()
{
    for (const auto& typeName : *this)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoLoadResourceTest, typeName.second, typeName.first);
    }
}

void System::LoadResourceWindowsTesting::DoLoadResourceTest(const DynamicLinkCharType* type, WindowsWord name)
{
    const auto resource = FindResourceInLibrary(GetInstance(), type, MakeIntreSource(name));

    ASSERT_UNEQUAL_NULL_PTR(resource);

    const auto global = GetResourceInLibrary(resource);

    ASSERT_NOT_THROW_EXCEPTION_1(LockResourceInLibraryTest, global);

    ASSERT_NOT_THROW_EXCEPTION_1(SizeofResourceInLibraryTest, resource);
}

System::DynamicLinkGlobal System::LoadResourceWindowsTesting::GetResourceInLibrary(DynamicLinkResource resource)
{
    const auto global = LoadResourceInLibrary(GetInstance(), resource);

    ASSERT_UNEQUAL_NULL_PTR(global);

    return global;
}

void System::LoadResourceWindowsTesting::LockResourceInLibraryTest(DynamicLinkGlobal global)
{
    const auto resourceLock = LockResourceInLibrary(global);

    ASSERT_UNEQUAL_NULL_PTR(resourceLock);
}

void System::LoadResourceWindowsTesting::SizeofResourceInLibraryTest(DynamicLinkResource resource)
{
    const auto size = SizeofResourceInLibrary(GetInstance(), resource);

    ASSERT_LESS(0u, size);
}
