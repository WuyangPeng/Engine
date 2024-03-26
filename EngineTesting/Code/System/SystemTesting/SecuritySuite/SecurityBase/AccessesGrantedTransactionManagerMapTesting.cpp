/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:28)

#include "AccessesGrantedTransactionManagerMapTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessesGrantedTransactionManagerMapTesting::AccessesGrantedTransactionManagerMapTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::TransactionManagerGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::TransactionManagerGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::TransactionManagerGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::TransactionManagerGenericRead | AccessGenericMask::TransactionManagerGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::TransactionManagerAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessesGrantedTransactionManagerMapTesting)

void System::AccessesGrantedTransactionManagerMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessesGrantedTransactionManagerMapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionManagerMapGenericMaskTest);
}

void System::AccessesGrantedTransactionManagerMapTesting::TransactionManagerMapGenericMaskTest()
{
    for (const auto [fileHandleDesiredAccess, accessGenericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTransactionManagerMapGenericMaskTest, fileHandleDesiredAccess, accessGenericMask);
    }
}

void System::AccessesGrantedTransactionManagerMapTesting::DoTransactionManagerMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetTransactionManagerMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionManagerAllAccess, enlistmentMapGenericMask));

    if (fileHandleDesiredAccess == FileHandleDesiredAccess::Read ||
        fileHandleDesiredAccess == FileHandleDesiredAccess::Write)
    {
        ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionManagerGenericRead | AccessGenericMask::TransactionManagerGenericWrite, enlistmentMapGenericMask));
    }
}
