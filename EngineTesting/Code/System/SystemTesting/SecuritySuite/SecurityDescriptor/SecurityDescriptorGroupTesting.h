///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 14:35)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SecurityDescriptorGroupTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SecurityDescriptorGroupTesting;
        using ParentType = UnitTest;

    public:
        explicit SecurityDescriptorGroupTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GroupTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H