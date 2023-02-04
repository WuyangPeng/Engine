///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/28 14:40)

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
        using ACLBuffer = std::vector<char>;

    protected:
        NODISCARD UserObjectSecurityBuffer GetUserObjectSecurity();
        NODISCARD AccessCheckACLPtr GetDacl(UserObjectSecurityBuffer& buffer);
        NODISCARD ACLBuffer GetACL(UserObjectSecurityBuffer& buffer, WindowsDWord aclBytesInUse);
        NODISCARD AccessCheckACLPtr GetAccessCheckACLPtr(ACLBuffer& buffer) const noexcept;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_ACE_TESTING_BASE_H