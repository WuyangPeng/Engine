///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/27 21:48)

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
    for (const auto& mask : masks)
    {
        const auto accessMask = mask.first;

        AccessCheckGenericMapping genericMapping{};
        const auto enlistmentMapGenericMask = GetTransactionManagerMapGenericMask(accessMask, genericMapping);

        ASSERT_ENUM_EQUAL(mask.second, enlistmentMapGenericMask);
    }
}
