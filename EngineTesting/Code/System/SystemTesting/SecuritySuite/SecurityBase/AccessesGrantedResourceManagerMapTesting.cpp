///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 0:47)

#include "AccessesGrantedResourceManagerMapTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessesGrantedResourceManagerMapTesting::AccessesGrantedResourceManagerMapTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::ResourceManagerGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::ResourceManagerGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::ResourceManagerGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::ResourceManagerGenericRead | AccessGenericMask::ResourceManagerGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::ResourceManagerAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessesGrantedResourceManagerMapTesting)

void System::AccessesGrantedResourceManagerMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessesGrantedResourceManagerMapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerMapGenericMaskTest);
}

void System::AccessesGrantedResourceManagerMapTesting::ResourceManagerMapGenericMaskTest()
{
    for (const auto accessMask : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoResourceManagerMapGenericMaskTest, accessMask.first, accessMask.second);
    }
}

void System::AccessesGrantedResourceManagerMapTesting::DoResourceManagerMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetResourceManagerMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::ResourceManagerAllAccess, enlistmentMapGenericMask));

    if (fileHandleDesiredAccess == FileHandleDesiredAccess::Read ||
        fileHandleDesiredAccess == FileHandleDesiredAccess::Write)
    {
        ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::ResourceManagerGenericRead | AccessGenericMask::ResourceManagerGenericWrite, enlistmentMapGenericMask));
    }
}
