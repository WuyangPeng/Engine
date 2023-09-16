///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:07)

#include "AccessesGrantedFileMapTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessesGrantedFileMapTesting::AccessesGrantedFileMapTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::FileGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::FileGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::FileGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::FileGenericRead | AccessGenericMask::FileGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::FileAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessesGrantedFileMapTesting)

void System::AccessesGrantedFileMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessesGrantedFileMapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileMapGenericMaskTest);
}

void System::AccessesGrantedFileMapTesting::FileMapGenericMaskTest()
{
    for (const auto accessMask : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFileMapGenericMaskTest, accessMask.first, accessMask.second);
    }
}

void System::AccessesGrantedFileMapTesting::DoFileMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetFileMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::FileAllAccess, enlistmentMapGenericMask));

    if (fileHandleDesiredAccess == FileHandleDesiredAccess::Read ||
        fileHandleDesiredAccess == FileHandleDesiredAccess::Write)
    {
        ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::FileGenericRead | AccessGenericMask::FileGenericWrite, enlistmentMapGenericMask));
    }
}
