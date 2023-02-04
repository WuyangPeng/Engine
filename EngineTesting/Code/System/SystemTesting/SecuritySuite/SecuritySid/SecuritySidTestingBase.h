///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:38)

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
        using SecuritySIDIndentifierAuthorityContainer = std::vector<SecuritySIDIndentifierAuthority>;
        using SecuritySIDIndentifierAuthorityContainerIter = SecuritySIDIndentifierAuthorityContainer::iterator;

    protected:
        NODISCARD SecuritySIDIndentifierAuthorityContainerIter begin() noexcept;
        NODISCARD SecuritySIDIndentifierAuthorityContainerIter end() noexcept;

    private:
        NODISCARD static SecuritySIDIndentifierAuthorityContainer GetSecuritySIDIndentifierAuthorityContainer();

    private:
        SecuritySIDIndentifierAuthorityContainer securitySIDIndentifierAuthorities;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_SID_TESTING_BASE_H