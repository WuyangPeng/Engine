///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/27 21:50)

#include "ResourceManagerMapGenericMaskTesting.h"
#include "System/FileManager/Flags/FileFlags.h"
#include "System/Security/AccessCheck.h"
#include "System/Security/Flags/AccessCheckFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::ResourceManagerMapGenericMaskTesting::ResourceManagerMapGenericMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      masks{ { FileHandleDesiredAccess::Read, AccessGenericMask::ResourceManagerGenericRead },
             { FileHandleDesiredAccess::Write, AccessGenericMask::ResourceManagerGenericWrite },
             { FileHandleDesiredAccess::Execute, AccessGenericMask::ResourceManagerGenericExecute },
             { FileHandleDesiredAccess::ReadWrite, AccessGenericMask::ResourceManagerGenericRead | AccessGenericMask::ResourceManagerGenericWrite },
             { FileHandleDesiredAccess::All, AccessGenericMask::ResourceManagerAllAccess } }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, ResourceManagerMapGenericMaskTesting)

void System::ResourceManagerMapGenericMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::ResourceManagerMapGenericMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ResourceManagerMapGenericMaskTest);
}

void System::ResourceManagerMapGenericMaskTesting::ResourceManagerMapGenericMaskTest()
{
    for (const auto& mask : masks)
    {
        const auto accessMask = mask.first;

        AccessCheckGenericMapping genericMapping{};
        const auto enlistmentMapGenericMask = GetResourceManagerMapGenericMask(accessMask, genericMapping);

        ASSERT_ENUM_EQUAL(mask.second, enlistmentMapGenericMask);
    }
}