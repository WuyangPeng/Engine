///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 19:15)

#include "MapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MapGenericMaskTesting::MapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MapGenericMaskTesting)

void System::MapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(FileMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionManagerMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(TransactionMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerMapGenericMaskTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EnlistmentMapGenericMaskTest);
}

void System::MapGenericMaskTesting::MapGenericMaskTest()
{
    AccessCheckGenericMapping genericMapping{};
    genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
    genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
    genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
    genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

    auto accessMask = EnumCastUnderlying<WindowsDWord>(FileHandleDesiredAccess::ReadWrite);

    GetMapGenericMask(&accessMask, &genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::FileGenericRead | AccessGenericMask::FileGenericWrite, UnderlyingCastEnum<AccessGenericMask>(accessMask));
}

void System::MapGenericMaskTesting::FileMapGenericMaskTest()
{
    constexpr auto accessMask = FileHandleDesiredAccess::Read;

    AccessCheckGenericMapping genericMapping{};

    const auto fileMapGenericMask = GetFileMapGenericMask(accessMask, genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::FileGenericRead, fileMapGenericMask);
}

void System::MapGenericMaskTesting::TransactionManagerMapGenericMaskTest()
{
    constexpr auto accessMask = FileHandleDesiredAccess::Write;

    AccessCheckGenericMapping genericMapping{};

    const auto transactionManagerMapGenericMask = GetTransactionManagerMapGenericMask(accessMask, genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::TransactionManagerGenericWrite, transactionManagerMapGenericMask);
}

void System::MapGenericMaskTesting::TransactionMapGenericMaskTest()
{
    constexpr auto accessMask = FileHandleDesiredAccess::Execute;

    AccessCheckGenericMapping genericMapping{};

    const auto transactionMapGenericMask = GetTransactionMapGenericMask(accessMask, genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::TransactionGenericExecute, transactionMapGenericMask);
}

void System::MapGenericMaskTesting::ResourceManagerMapGenericMaskTest()
{
    constexpr auto accessMask = FileHandleDesiredAccess::All;

    AccessCheckGenericMapping genericMapping{};

    const auto resourceManagerMapGenericMask = GetResourceManagerMapGenericMask(accessMask, genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::ResourceManagerAllAccess, resourceManagerMapGenericMask);
}

void System::MapGenericMaskTesting::EnlistmentMapGenericMaskTest()
{
    constexpr auto accessMask = FileHandleDesiredAccess::ReadWrite;

    AccessCheckGenericMapping genericMapping{};

    const auto enlistmentMapGenericMask = GetEnlistmentMapGenericMask(accessMask, genericMapping);

    ASSERT_ENUM_EQUAL(AccessGenericMask::EnlistmentGenericRead | AccessGenericMask::EnlistmentGenericWrite, enlistmentMapGenericMask);
}
