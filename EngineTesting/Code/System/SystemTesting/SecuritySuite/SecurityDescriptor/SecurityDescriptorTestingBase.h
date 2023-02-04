///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 19:21)

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