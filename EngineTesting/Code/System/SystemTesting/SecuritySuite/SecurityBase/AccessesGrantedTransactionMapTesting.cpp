/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 14:28)

#include "AccessesGrantedTransactionMapTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessesGrantedTransactionMapTesting::AccessesGrantedTransactionMapTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::TransactionGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::TransactionGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::TransactionGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::TransactionGenericRead | AccessGenericMask::TransactionGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::TransactionAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessesGrantedTransactionMapTesting)

void System::AccessesGrantedTransactionMapTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessesGrantedTransactionMapTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionMapGenericMaskTest);
}

void System::AccessesGrantedTransactionMapTesting::TransactionMapGenericMaskTest()
{
    for (const auto [fileHandleDesiredAccess, accessGenericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTransactionMapGenericMaskTest, fileHandleDesiredAccess, accessGenericMask);
    }
}

void System::AccessesGrantedTransactionMapTesting::DoTransactionMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetTransactionMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(accessGenericMask, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionAllAccess, enlistmentMapGenericMask));

    if (fileHandleDesiredAccess == FileHandleDesiredAccess::Read ||
        fileHandleDesiredAccess == FileHandleDesiredAccess::Write)
    {
        ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionGenericRead | AccessGenericMask::TransactionGenericWrite, enlistmentMapGenericMask));
    }
}
