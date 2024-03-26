/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:35)

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
