///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/29 20:11)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H

#include "SecurityDescriptorTestingBase.h"

namespace System
{
    class SecurityDescriptorGroupTesting final : public SecurityDescriptorTestingBase
    {
    public:
        using ClassType = SecurityDescriptorGroupTesting;
        using ParentType = SecurityDescriptorTestingBase;

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