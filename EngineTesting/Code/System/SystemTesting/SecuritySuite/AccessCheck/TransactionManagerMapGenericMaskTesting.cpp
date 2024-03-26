/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:36)

#include "TransactionManagerMapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::TransactionManagerMapGenericMaskTesting::TransactionManagerMapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::TransactionManagerGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::TransactionManagerGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::TransactionManagerGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::TransactionManagerGenericRead | AccessGenericMask::TransactionManagerGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::TransactionManagerAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TransactionManagerMapGenericMaskTesting)

void System::TransactionManagerMapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::TransactionManagerMapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionManagerMapGenericMaskTest);
}

void System::TransactionManagerMapGenericMaskTesting::TransactionManagerMapGenericMaskTest()
{
    for (const auto& [accessMask, genericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTransactionManagerMapGenericMaskTest, accessMask, genericMask);
    }
}

void System::TransactionManagerMapGenericMaskTesting::DoTransactionManagerMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};
    const auto enlistmentMapGenericMask = GetTransactionManagerMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_ENUM_EQUAL(accessGenericMask, enlistmentMapGenericMask);
}
