///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/27 23:41)

#ifndef SYSTEM_SECURITY_SUITE_ADD_ACCESS_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_ADD_ACCESS_TESTING_BASE_H

#include "System/Security/Fwd/SecurityFlagsFwd.h"
#include "System/Security/Using/SecurityAclUsing.h"
#include "System/Security/Using/SecuritySidUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>
#include <random>
#include <vector>

namespace System
{
    class AddAccessTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = AddAccessTestingBase;
        using ParentType = UnitTest;

    public:
        explicit AddAccessTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto aclBufferSize = 4096u;

        using ACLBufferType = std::array<char, aclBufferSize>;
        using SpecificAccessContainer = std::vector<SpecificAccess>;
        using SpecificAccessContainerConstIter = SpecificAccessContainer::const_iterator;
        using ControlACEInheritanceContainer = std::vector<ControlACEInheritance>;

    protected:
        void RandomShuffle();
        NODISCARD SpecificAccessContainerConstIter GetSpecificAccessBegin() const noexcept;
        NODISCARD SpecificAccessContainerConstIter GetSpecificAccessEnd() const noexcept;
        NODISCARD ACLBufferType GetACLBuffer(AccessControlListRevision accessControlListRevision);
        NODISCARD AccessCheckACLPtr GetAccessCheckACLPtr(ACLBufferType& aclBuffer) const noexcept;
        NODISCARD SecuritySID GetSecuritySID();
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD SpecificAccess GetSpecificAccess(size_t index) const;
        NODISCARD ControlACEInheritance GetControlACEInheritance(size_t index) const;

    private:
        ControlACEInheritanceContainer controlACEInheritances;
        SpecificAccessContainer specificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_TESTING_BASE_H