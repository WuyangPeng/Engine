///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 14:31)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SecurityDescriptorControlTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorControlTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorControlTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ControlTest();

    private:
        using SecurityDescriptorControlBitsFlagsCollection = std::vector<SecurityDescriptorControlBits>;

    private:
        SecurityDescriptorControlBitsFlagsCollection securityDescriptorControlBitsFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_CONTROL_TESTING_H