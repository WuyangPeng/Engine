///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/25 20:28)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class SecurityAccessMaskTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = SecurityAccessMaskTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit SecurityAccessMaskTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetSecurityAccessMaskTest();

        void DoSetSecurityAccessMaskTest(SecurityRequestedInformation securityRequestedInformation);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H