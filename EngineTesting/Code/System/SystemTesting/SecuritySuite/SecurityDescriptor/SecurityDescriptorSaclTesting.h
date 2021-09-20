///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 14:42)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_SACL_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_SACL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecurityDescriptorSaclTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorSaclTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorSaclTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SaclTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_SACL_TESTING_H