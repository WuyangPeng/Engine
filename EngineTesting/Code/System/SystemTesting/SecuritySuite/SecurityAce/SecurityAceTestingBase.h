/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:24)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_ACE_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_SECURITY_ACE_TESTING_BASE_H

#include "System/Security/Using/SecurityAclUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecurityAceTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityAceTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SecurityAceTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using UserObjectSecurityBuffer = std::vector<char>;
        using AclBuffer = std::vector<char>;

    protected:
        NODISCARD UserObjectSecurityBuffer GetUserObjectSecurity();
        NODISCARD AccessCheckAclPtr GetDacl(UserObjectSecurityBuffer& buffer);
        NODISCARD AclBuffer GetAcl(UserObjectSecurityBuffer& buffer, WindowsDWord aclBytesInUse);
        NODISCARD static AccessCheckAclPtr GetAccessCheckAclPtr(AclBuffer& buffer) noexcept;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_ACE_TESTING_BASE_H