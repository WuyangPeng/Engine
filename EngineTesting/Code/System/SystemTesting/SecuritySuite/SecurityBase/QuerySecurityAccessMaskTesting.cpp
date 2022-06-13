///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/14 15:46)

#include "QuerySecurityAccessMaskTesting.h"
#include "System/Security/Flags/CreateSecurityFlags.h"
#include "System/Security/SecurityBase.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::QuerySecurityAccessMaskTesting::QuerySecurityAccessMaskTesting(const OStreamShared& stream)
    : ParentType{ stream },
      securityRequestedInformationFlags{ SecurityRequestedInformation::Owner,
                                         SecurityRequestedInformation::Group,
                                         SecurityRequestedInformation::Dacl,
                                         SecurityRequestedInformation::Sacl,
                                         SecurityRequestedInformation::Label }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, QuerySecurityAccessMaskTesting)

void System::QuerySecurityAccessMaskTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::QuerySecurityAccessMaskTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(QuerySecurityAccessMaskTest);
}

void System::QuerySecurityAccessMaskTesting::QuerySecurityAccessMaskTest()
{
    for (auto SecurityRequestedInformation : securityRequestedInformationFlags)
    {
        WindowsDWord desiredAccess{ 0 };

        QuerySystemSecurityAccessMask(SecurityRequestedInformation, &desiredAccess);
        ASSERT_LESS(0u, desiredAccess);
    }
}
