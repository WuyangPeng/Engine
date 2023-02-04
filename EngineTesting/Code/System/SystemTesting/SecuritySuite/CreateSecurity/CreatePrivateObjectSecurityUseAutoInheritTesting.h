///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/25 21:26)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_USE_AUTO_INHERIT_TESTING_H
#define SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_USE_AUTO_INHERIT_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class CreatePrivateObjectSecurityUseAutoInheritTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = CreatePrivateObjectSecurityUseAutoInheritTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit CreatePrivateObjectSecurityUseAutoInheritTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreatePrivateObjectSecurityTest();

        void DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle);
        void SetSystemFileSecurityTest(SecurityDescriptorPtr descriptor);
        void CreateSecurityTest(SecurityAutoInherit securityAutoInherit, WindowsHandle tokenHandle);

    private:
        String setFileName;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_USE_AUTO_INHERIT_TESTING_H