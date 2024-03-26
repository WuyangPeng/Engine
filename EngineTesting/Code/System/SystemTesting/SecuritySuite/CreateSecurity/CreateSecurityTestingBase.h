/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:19)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H

#include "System/Security/Flags/AccessCheckFlags.h"
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

        NODISCARD constexpr static AccessCheckGenericMapping GetAccessCheckGenericMapping() noexcept
        {
            AccessCheckGenericMapping genericMapping{};
            genericMapping.GenericRead = EnumCastUnderlying(AccessGenericMask::FileGenericRead);
            genericMapping.GenericWrite = EnumCastUnderlying(AccessGenericMask::FileGenericWrite);
            genericMapping.GenericExecute = EnumCastUnderlying(AccessGenericMask::FileGenericExecute);
            genericMapping.GenericAll = EnumCastUnderlying(AccessGenericMask::FileAllAccess);

            return genericMapping;
        }

    private:
        SecurityRequestedInformationContainer securityRequestedInformationContainer;
        SecurityAutoInheritContainer securityAutoInherits;
        bool tokenIsElevated;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_SECURITY_TESTING_BASE_H