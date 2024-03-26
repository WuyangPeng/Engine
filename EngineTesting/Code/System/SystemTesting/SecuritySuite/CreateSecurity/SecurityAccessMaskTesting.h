/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:19)

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
        void DoRunUnitTest() override;
        void MainTest();

        void SetSecurityAccessMaskTest();

        void DoSetSecurityAccessMaskTest(SecurityRequestedInformation securityRequestedInformation);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_ACCESS_MASK_TESTING_H