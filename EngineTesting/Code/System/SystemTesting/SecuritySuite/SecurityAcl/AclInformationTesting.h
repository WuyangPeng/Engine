///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:43)

#ifndef SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H
#define SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class AclInformationTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AclInformationTesting;
        using ParentType = UnitTest;

    public:
        explicit AclInformationTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InformationTest();
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ACL_INFORMATION_TESTING_H