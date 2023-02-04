///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/25 20:16)

#ifndef SYSTEM_SECURITY_SUITE_KERNEL_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_KERNEL_OBJECT_SECURITY_TESTING_H

#include "CreateSecurityTestingBase.h"

namespace System
{
    class KernelObjectSecurityTesting final : public CreateSecurityTestingBase
    {
    public:
        using ClassType = KernelObjectSecurityTesting;
        using ParentType = CreateSecurityTestingBase;

    public:
        explicit KernelObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void KernelObjectSecurityTest();

        void DoKernelObjectSecurityTest(WindowsHandle tokenHandle);
        void SetKernelObjectSecurityTest(WindowsHandle tokenHandle, SecurityRequestedInformation securityRequestedInformation);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_KERNEL_OBJECT_SECURITY_TESTING_H