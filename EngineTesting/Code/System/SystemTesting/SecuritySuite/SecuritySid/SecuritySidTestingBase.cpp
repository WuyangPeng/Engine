///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:10)

#include "SecuritySidTestingBase.h"
#include "System/Helper/SecuritySidMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::SecuritySidTestingBase::SecuritySidTestingBase(const OStreamShared& stream)
    : ParentType{ stream }, securitySIDIdentifierAuthorities{ GetSecuritySidIdentifierAuthorityContainer() }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

System::SecuritySidTestingBase::SecuritySidIdentifierAuthorityContainer System::SecuritySidTestingBase::GetSecuritySidIdentifierAuthorityContainer()
{
    SecuritySidIdentifierAuthorityContainer securitySidIdentifierAuthority{};

    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_NULL_SID_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_WORLD_SID_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_LOCAL_SID_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_CREATOR_SID_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_NON_UNIQUE_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_RESOURCE_MANAGER_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_NT_AUTHORITY);
    securitySidIdentifierAuthority.emplace_back(SecuritySidIdentifierAuthority SYSTEM_SECURITY_MANDATORY_LABEL_AUTHORITY);

    return securitySidIdentifierAuthority;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, SecuritySidTestingBase)

System::SecuritySidTestingBase::SecuritySidIdentifierAuthorityContainerIter System::SecuritySidTestingBase::begin() noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securitySIDIdentifierAuthorities.begin();
}

System::SecuritySidTestingBase::SecuritySidIdentifierAuthorityContainerIter System::SecuritySidTestingBase::end() noexcept
{
    SYSTEM_CLASS_IS_VALID_CONST_1;

    return securitySIDIdentifierAuthorities.end();
}
