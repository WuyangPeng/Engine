///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 13:52)

#ifndef SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_DESCRIPTOR_TESTING_H
#define SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_DESCRIPTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InitializeSecurityDescriptorTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InitializeSecurityDescriptorTesting;
        using ParentType = UnitTest;

    public:
        explicit InitializeSecurityDescriptorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void InitializeSecurityDescriptorTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_INITIALIZE_SECURITY_DESCRIPTOR_TESTING_H