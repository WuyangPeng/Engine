///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 19:08)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_USE_ACE_FLAGS_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_USE_ACE_FLAGS_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class AddAccessAllowedAceUseAceFlagsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddAccessAllowedAceUseAceFlagsTesting;
        using ParentType = UnitTest;

    public:
        explicit AddAccessAllowedAceUseAceFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAccessAllowedAccessControlEntriesTest();

    private:
        using ControlACEInheritanceFlagsCollection = std::vector<ControlACEInheritance>;
        using SpecificAccessFlagsCollection = std::vector<SpecificAccess>;

    private:
        ControlACEInheritanceFlagsCollection controlACEInheritanceFlags;
        SpecificAccessFlagsCollection specificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_ALLOWED_ACE_USE_ACE_FLAGS_TESTING_H