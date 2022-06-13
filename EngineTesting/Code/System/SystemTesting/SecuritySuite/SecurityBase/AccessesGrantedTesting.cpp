///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/14 15:44)

#include "AccessesGrantedTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::AccessesGrantedTesting::AccessesGrantedTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, AccessesGrantedTesting)

void System::AccessesGrantedTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::AccessesGrantedTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(FileMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionManagerMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnlistmentMapGenericMaskTest);
}

void System::AccessesGrantedTesting::FileMapGenericMaskTest()
{
    const auto accessMask = FileHandleDesiredAccess::Read;

    AccessCheckGenericMapping genericMapping{};

    const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(AccessGenericMask::FileGenericRead, fileMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::FileAllAccess, fileMapGenericMask));
}

void System::AccessesGrantedTesting::TransactionManagerMapGenericMaskTest()
{
    const auto accessMask = FileHandleDesiredAccess::Write;

    AccessCheckGenericMapping genericMapping{};

    const auto transactionManagerMapGenericMask = GetTransactionManagerMapGenericMask(accessMask, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(AccessGenericMask::TransactionManagerGenericWrite, transactionManagerMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionManagerAllAccess, transactionManagerMapGenericMask));
}

void System::AccessesGrantedTesting::TransactionMapGenericMaskTest()
{
    const auto accessMask = FileHandleDesiredAccess::Execute;

    AccessCheckGenericMapping genericMapping{};

    const auto transactionMapGenericMask = GetTransactionMapGenericMask(accessMask, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(AccessGenericMask::TransactionGenericExecute, transactionMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::TransactionAllAccess, transactionMapGenericMask));
}

void System::AccessesGrantedTesting::ResourceManagerMapGenericMaskTest()
{
    const auto accessMask = FileHandleDesiredAccess::All;

    AccessCheckGenericMapping genericMapping{};

    const auto resourceManagerMapGenericMask = GetResourceManagerMapGenericMask(accessMask, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(AccessGenericMask::ResourceManagerAllAccess, resourceManagerMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::ResourceManagerAllAccess, resourceManagerMapGenericMask));
}

void System::AccessesGrantedTesting::EnlistmentMapGenericMaskTest()
{
    const auto accessMask = FileHandleDesiredAccess::ReadWrite;

    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetEnlistmentMapGenericMask(accessMask, genericMapping);

    ASSERT_TRUE(IsAreAllAccessesGranted(AccessGenericMask::EnlistmentGenericRead | AccessGenericMask::EnlistmentGenericWrite, enlistmentMapGenericMask));
    ASSERT_TRUE(IsAreAnyAccessesGranted(AccessGenericMask::EnlistmentAllAccess, enlistmentMapGenericMask));
}
