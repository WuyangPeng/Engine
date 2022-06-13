///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:12)

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