///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/02 15:49)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class AddAccessAllowedAceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddAccessAllowedAceTesting;
        using ParentType = UnitTest;

    public:
        explicit AddAccessAllowedAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AddAccessAllowedAccessControlEntriesTest();

    private:
        using SpecificAccessFlagsCollection = std::vector<SpecificAccess>;

    private:
        SpecificAccessFlagsCollection specificAccessFlags;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_TESTING_H