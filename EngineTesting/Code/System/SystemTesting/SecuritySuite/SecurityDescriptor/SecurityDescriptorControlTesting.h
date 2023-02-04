///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/29 20:01)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H

#include "SecurityDescriptorTestingBase.h"
#include "System/Security/Using/CreateSecurityUsing.h"

namespace System
{
    class SecurityDescriptorControlTesting final : public SecurityDescriptorTestingBase
    {
    public:
        using ClassType = SecurityDescriptorControlTesting;
        using ParentType = SecurityDescriptorTestingBase;

    public:
        explicit SecurityDescriptorControlTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ControlTest();

        void DoControlTest(SecurityDescriptor& securityDescriptor, SecurityDescriptorControlBits bits);

    private:
        using SecurityDescriptorControlBitsContainer = std::vector<SecurityDescriptorControlBits>;

    private:
        SecurityDescriptorControlBitsContainer securityDescriptorControlBitses;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H