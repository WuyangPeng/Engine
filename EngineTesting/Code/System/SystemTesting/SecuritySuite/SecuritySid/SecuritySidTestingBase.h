/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:27)

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
        SecuritySidIdentifierAuthorityContainer securitySidIdentifierAuthorities;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_SID_TESTING_BASE_H