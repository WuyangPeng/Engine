///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:57)

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
