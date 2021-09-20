///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/04 10:19)

#ifndef SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AdjustTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AdjustTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit AdjustTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetAdjustTokenPrivilegesTest();
        void GetAdjustTokenGroupsTest();

    private:
        using LookupPrivilegeNameCollection = std::vector<String>;
        using SecurityTokenAttributesGroupFlagsCollection = std::vector<SecurityTokenAttributesGroup>;

    private:
        LookupPrivilegeNameCollection lookupPrivilegeName;
        SecurityTokenAttributesGroupFlagsCollection securityTokenAttributesGroupFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADJUST_TOKEN_TESTING_H