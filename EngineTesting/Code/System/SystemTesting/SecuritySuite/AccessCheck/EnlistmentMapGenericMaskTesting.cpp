/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:35)

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
    for (const auto& [accessMask, genericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoEnlistmentMapGenericMaskTest, accessMask, genericMask);
    }
}

void System::EnlistmentMapGenericMaskTesting::DoEnlistmentMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};
    const auto enlistmentMapGenericMask = GetEnlistmentMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_EQUAL(accessGenericMask, enlistmentMapGenericMask);
}