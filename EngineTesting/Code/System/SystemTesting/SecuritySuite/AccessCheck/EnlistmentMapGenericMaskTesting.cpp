///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:57)

#include "EnlistmentMapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::EnlistmentMapGenericMaskTesting::EnlistmentMapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::EnlistmentGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::EnlistmentGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::EnlistmentGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::EnlistmentGenericRead | AccessGenericMask::EnlistmentGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::EnlistmentAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, EnlistmentMapGenericMaskTesting)

void System::EnlistmentMapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::EnlistmentMapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EnlistmentMapGenericMaskTest);
}

void System::EnlistmentMapGenericMaskTesting::EnlistmentMapGenericMaskTest()
{
    for (const auto& mask : masks)
    {
        const auto accessMask = mask.first;

        AccessCheckGenericMapping genericMapping{};
        const auto enlistmentMapGenericMask = GetEnlistmentMapGenericMask(accessMask, genericMapping);

        ASSERT_ENUM_EQUAL(mask.second, enlistmentMapGenericMask);
    }
}
