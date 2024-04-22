/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:35)

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

void System::FileMapGenericMaskTesting::DoFileMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};
    const auto enlistmentMapGenericMask = GetFileMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_EQUAL(accessGenericMask, enlistmentMapGenericMask);
}

void System::FileMapGenericMaskTesting::FileMapGenericMaskTest()
{
    for (const auto& [accessMask, genericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoFileMapGenericMaskTest, accessMask, genericMask);
    }
}
