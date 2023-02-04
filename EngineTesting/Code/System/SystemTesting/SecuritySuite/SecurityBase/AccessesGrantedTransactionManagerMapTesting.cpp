///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 0:50)

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
    for (const auto accessMask : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTransactionManagerMapGenericMaskTest, accessMask.first, accessMask.second);
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
