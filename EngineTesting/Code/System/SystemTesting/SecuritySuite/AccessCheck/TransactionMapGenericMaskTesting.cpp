///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:57)

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
    for (const auto& mask : masks)
    {
        const auto accessMask = mask.first;

        AccessCheckGenericMapping genericMapping{};
        const auto enlistmentMapGenericMask = GetTransactionMapGenericMask(accessMask, genericMapping);

        ASSERT_ENUM_EQUAL(mask.second, enlistmentMapGenericMask);
    }
}
