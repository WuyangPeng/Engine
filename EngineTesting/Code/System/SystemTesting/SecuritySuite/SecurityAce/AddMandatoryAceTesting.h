///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/11/01 21:44)

#ifndef SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class AddMandatoryAceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddMandatoryAceTesting;
        using ParentType = UnitTest;

    public:
        explicit AddMandatoryAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void GetAccessControlEntriesTest();

    private:
        using ControlACEInheritanceFlagsCollection = std::vector<ControlACEInheritance>;
        using MandatoryPolicyFlagsCollection = std::vector<MandatoryPolicy>;

    private:
        ControlACEInheritanceFlagsCollection controlACEInheritanceFlags;
        MandatoryPolicyFlagsCollection mandatoryPolicyFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_MONDATORY_ACE_TESTING_H