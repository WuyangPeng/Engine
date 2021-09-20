///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/06/03 14:08)

#ifndef SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H
#define SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class AddAuditAccessObjectAceTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddAuditAccessObjectAceTesting;
        using ParentType = UnitTest;

    public:
        explicit AddAuditAccessObjectAceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void AddAuditAccessObjectAceTest();

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

#endif  // SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H