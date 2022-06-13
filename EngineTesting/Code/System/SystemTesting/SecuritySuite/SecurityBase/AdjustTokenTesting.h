///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 19:10)

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