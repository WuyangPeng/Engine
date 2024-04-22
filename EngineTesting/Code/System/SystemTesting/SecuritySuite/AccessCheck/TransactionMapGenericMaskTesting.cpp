/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:36)

#include "TransactionMapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::TransactionMapGenericMaskTesting::TransactionMapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::TransactionGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::TransactionGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::TransactionGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::TransactionGenericRead | AccessGenericMask::TransactionGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::TransactionAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, TransactionMapGenericMaskTesting)

void System::TransactionMapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::TransactionMapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionMapGenericMaskTest);
}

void System::TransactionMapGenericMaskTesting::TransactionMapGenericMaskTest()
{
    for (const auto& [accessMask, genericMask] : masks)
    {
        ASSERT_NOT_THROW_EXCEPTION_2(DoTransactionMapGenericMaskTest, accessMask, genericMask);
    }
}

void System::TransactionMapGenericMaskTesting::DoTransactionMapGenericMaskTest(FileHandleDesiredAccess fileHandleDesiredAccess, AccessGenericMask accessGenericMask)
{
    AccessCheckGenericMapping genericMapping{};
    const auto enlistmentMapGenericMask = GetTransactionMapGenericMask(fileHandleDesiredAccess, genericMapping);

    ASSERT_EQUAL(accessGenericMask, enlistmentMapGenericMask);
}