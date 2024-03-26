/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:18)

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

        using AclBufferType = std::array<char, aclBufferSize>;
        using SpecificAccessContainer = std::vector<SpecificAccess>;
        using SpecificAccessContainerConstIter = SpecificAccessContainer::const_iterator;
        using ControlAceInheritanceContainer = std::vector<ControlAceInheritance>;

    protected:
        void RandomShuffle();
        NODISCARD SpecificAccessContainerConstIter GetSpecificAccessBegin() const noexcept;
        NODISCARD SpecificAccessContainerConstIter GetSpecificAccessEnd() const noexcept;
        NODISCARD AclBufferType GetAclBuffer(AccessControlListRevision accessControlListRevision);
        NODISCARD AccessCheckAclPtr GetAccessCheckAclPtr(AclBufferType& aclBuffer) const noexcept;
        NODISCARD SecuritySid GetSecuritySid();
        NODISCARD size_t GetMaxSize() const noexcept;
        NODISCARD SpecificAccess GetSpecificAccess(size_t index) const;
        NODISCARD ControlAceInheritance GetControlAceInheritance(size_t index) const;

    private:
        ControlAceInheritanceContainer controlAceInheritances;
        SpecificAccessContainer specificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_ADD_ACCESS_TESTING_BASE_H