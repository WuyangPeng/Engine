///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:47)

#ifndef SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H
#define SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class SetPrivateObjectSecurityTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SetPrivateObjectSecurityTesting;
        using ParentType = UnitTest;

    public:
        explicit SetPrivateObjectSecurityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SetPrivateObjectSecurityTest();

    private:
        using SecurityRequestedInformationFlagsContainer = std::vector<SecurityRequestedInformation>;
        using SecurityAutoInheritFlagsContainer = std::vector<SecurityAutoInherit>;

    private:
        SecurityRequestedInformationFlagsContainer securityRequestedInformationFlags;
        SecurityAutoInheritFlagsContainer securityAutoInheritFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_SET_PRIVATE_OBJECT_SECURITY_TESTING_H