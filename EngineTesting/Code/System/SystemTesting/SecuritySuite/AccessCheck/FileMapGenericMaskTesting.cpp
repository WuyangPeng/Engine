///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:57)

#include "FileMapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::FileMapGenericMaskTesting::FileMapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::FileGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::FileGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::FileGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::FileGenericRead | AccessGenericMask::FileGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::FileAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, FileMapGenericMaskTesting)

void System::FileMapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::FileMapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileMapGenericMaskTest);
}

void System::FileMapGenericMaskTesting::FileMapGenericMaskTest()
{
    for (const auto& mask : masks)
    {
        const auto accessMask = mask.first;

        AccessCheckGenericMapping genericMapping{};
        const auto enlistmentMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

        ASSERT_ENUM_EQUAL(mask.second, enlistmentMapGenericMask);
    }
}
