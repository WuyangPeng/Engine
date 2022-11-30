///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:37)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_OWNER_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_OWNER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecurityDescriptorOwnerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorOwnerTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorOwnerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void OwnerTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_OWNER_TESTING_H