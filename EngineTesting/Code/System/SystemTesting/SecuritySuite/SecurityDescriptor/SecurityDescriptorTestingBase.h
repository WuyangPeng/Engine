/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:26)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_TESTING_BASE_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecurityDescriptorTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorTestingBase;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        using BufferType = std::vector<char>;

    protected:
        BufferType GetUserObjectSecurity(SecurityRequestedInformation requested);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_TESTING_BASE_H