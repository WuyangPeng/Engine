/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 13:26)

#ifndef SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DISCRETIONARY_ACCESS_CONTROL_LIST_TESTING_H
#define SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DISCRETIONARY_ACCESS_CONTROL_LIST_TESTING_H

#include "SecurityDescriptorTestingBase.h"

namespace System
{
    class SecurityDescriptorDiscretionaryAccessControlListTesting final : public SecurityDescriptorTestingBase
    {
    public:
        using ClassType = SecurityDescriptorDiscretionaryAccessControlListTesting;
        using ParentType = SecurityDescriptorTestingBase;

    public:
        explicit SecurityDescriptorDiscretionaryAccessControlListTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void DiscretionaryAccessControlListTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_DISCRETIONARY_ACCESS_CONTROL_LIST_TESTING_H