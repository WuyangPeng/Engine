///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/11/01 21:54)

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
        using ControlACEInheritanceFlagsContainer = std::vector<ControlACEInheritance>;
        using SpecificAccessFlagsContainer = std::vector<SpecificAccess>;

    private:
        ControlACEInheritanceFlagsContainer controlACEInheritanceFlags;
        SpecificAccessFlagsContainer specificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_AUDIT_ACCESS_OBJECT_ACE_TESTING_H