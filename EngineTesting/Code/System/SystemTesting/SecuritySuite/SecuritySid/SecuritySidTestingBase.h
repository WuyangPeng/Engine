///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:53)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_SID_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_SECURITY_SID_TESTING_BASE_H

#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecuritySidTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecuritySidTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SecuritySidTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;
        using SecuritySidIdentifierAuthorityContainer = std::vector<SecuritySidIdentifierAuthority>;
        using SecuritySidIdentifierAuthorityContainerIter = SecuritySidIdentifierAuthorityContainer::iterator;

    protected:
        NODISCARD SecuritySidIdentifierAuthorityContainerIter begin() noexcept;
        NODISCARD SecuritySidIdentifierAuthorityContainerIter end() noexcept;

    private:
        NODISCARD static SecuritySidIdentifierAuthorityContainer GetSecuritySidIdentifierAuthorityContainer();

    private:
        SecuritySidIdentifierAuthorityContainer securitySIDIdentifierAuthorities;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_SID_TESTING_BASE_H