///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/05/29 21:37)

#ifndef SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H
#define SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class CreatePrivateObjectSecurityWithMultipleInheritanceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreatePrivateObjectSecurityWithMultipleInheritanceTesting;
        using ParentType = UnitTest;

    public:
        explicit CreatePrivateObjectSecurityWithMultipleInheritanceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void CreatePrivateObjectSecurityTest();

    private:
        using SecurityAutoInheritFlagsCollection = std::vector<SecurityAutoInherit>;

    private:
        SecurityAutoInheritFlagsCollection securityAutoInheritFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_CREATE_PRIVATE_OBJECT_SECURITY_WITH_MULTIPLE_INHERITANCE_TESTING_H