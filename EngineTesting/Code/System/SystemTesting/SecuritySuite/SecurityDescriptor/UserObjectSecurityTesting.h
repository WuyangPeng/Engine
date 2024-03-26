/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:26)

#ifndef SYSTEM_SECURITY_SUITE_USER_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_USER_OBJECT_SECURITY_TESTING_H

#include "SecurityDescriptorTestingBase.h"
#include "System/Security/Fwd/SecurityFlagsFwd.h"

namespace System
{
    class UserObjectSecurityTesting final : public SecurityDescriptorTestingBase
    {
    public:
        using ClassType = UserObjectSecurityTesting;
        using ParentType = SecurityDescriptorTestingBase;

    public:
        explicit UserObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void UserObjectSecurityTest();

        void DoUserObjectSecurityTest(SecurityRequestedInformation requested);

    private:
        using SecurityRequestedInformationContainer = std::vector<SecurityRequestedInformation>;

    private:
        SecurityRequestedInformationContainer securityRequestedInformationContainer;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_USER_OBJECT_SECURITY_TESTING_H