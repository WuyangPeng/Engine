///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/02 15:49)

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