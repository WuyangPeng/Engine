///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:43)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H
#define SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class CreatePrivateObjectSecurityWithMultipleInheritanceTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = CreatePrivateObjectSecurityWithMultipleInheritanceTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit CreatePrivateObjectSecurityWithMultipleInheritanceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreatePrivateObjectSecurityTest();

        void DoCreatePrivateObjectSecurityTest(WindowsHandle tokenHandle);
        void CreateSecurityTest(SecurityAutoInherit securityAutoInherit, WindowsHandle tokenHandle);

    private:
        String setFileName;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H