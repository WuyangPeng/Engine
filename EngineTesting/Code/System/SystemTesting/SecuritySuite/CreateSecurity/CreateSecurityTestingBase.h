///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/25 18:27)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Security/Using/CreateSecurityUsing.h"
#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreateSecurityTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateSecurityTestingBase;
        using ParentType = UnitTest;

    public:
        explicit CreateSecurityTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;
        using SecurityRequestedInformationContainer = std::vector<SecurityRequestedInformation>;
        using SecurityRequestedInformationContainerConstIter = SecurityRequestedInformationContainer::const_iterator;
        using SecurityAutoInheritContainer = std::vector<SecurityAutoInherit>;
        using SecurityAutoInheritContainerConstIter = SecurityAutoInheritContainer::const_iterator;

    protected:
        NODISCARD SecurityRequestedInformationContainerConstIter begin() const noexcept;
        NODISCARD SecurityRequestedInformationContainerConstIter end() const noexcept;
        NODISCARD SecurityAutoInheritContainerConstIter GetSecurityAutoInheritBegin() const noexcept;
        NODISCARD SecurityAutoInheritContainerConstIter GetSecurityAutoInheritEnd() const noexcept;
        NODISCARD bool GetTokenIsElevated() const noexcept;
        NODISCARD WindowsHandle OpenProcessToken();
        void CloseProcessTokenTest(WindowsHandle tokenHandle);
        void CreatePrivateObjectSecurity(WindowsHandle tokenHandle, SecurityDescriptorPtr& descriptor);
        void DestroyPrivateObjectSecurityTest(SecurityDescriptorPtr descriptor);
        NODISCARD AccessCheckGenericMapping GetAccessCheckGenericMapping() noexcept;

    private:
        SecurityRequestedInformationContainer securityRequestedInformations;
        SecurityAutoInheritContainer securityAutoInherits;
        bool tokenIsElevated;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H