///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:37)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DACL_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DACL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecurityDescriptorDaclTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorDaclTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorDaclTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DaclTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DACL_TESTING_H