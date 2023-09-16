///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 13:52)

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
        void DoRunUnitTest() override;
        void MainTest();

        void GroupTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SECURITY_DESCRIPTOR_GROUP_TESTING_H