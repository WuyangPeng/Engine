///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:41)

#ifndef SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_BASE_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AdjustTokenTestingBase final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AdjustTokenTestingBase;
        using ParentType = UnitTest;

    public:
        explicit AdjustTokenTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetAdjustTokenPrivilegesTest();
        void GetAdjustTokenGroupsTest();

    private:
        using LookupPrivilegeNameContainer = std::vector<String>;
        using SecurityTokenAttributesGroupFlagsContainer = std::vector<SecurityTokenAttributesGroup>;

    private:
        LookupPrivilegeNameContainer lookupPrivilegeName;
        SecurityTokenAttributesGroupFlagsContainer securityTokenAttributesGroupFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_BASE_H