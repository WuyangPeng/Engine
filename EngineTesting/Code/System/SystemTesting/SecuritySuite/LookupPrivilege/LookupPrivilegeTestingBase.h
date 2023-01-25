///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/25 11:47)

#ifndef SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_BASE_H
#define SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_BASE_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <array>
#include <vector>

namespace System
{
    class LookupPrivilegeTestingBase : public CoreTools::UnitTest
    {
    public:
        using ClassType = LookupPrivilegeTestingBase;
        using ParentType = UnitTest;

    public:
        explicit LookupPrivilegeTestingBase(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        static constexpr auto bufferSize = 256;
        using BufferType = std::array<TChar, bufferSize>;
        using LookupPrivilegeNameContainer = std::vector<String>;
        using LookupPrivilegeNameContainerConstIter = LookupPrivilegeNameContainer::const_iterator;

    protected:
        NODISCARD LookupPrivilegeNameContainerConstIter begin() const noexcept;
        NODISCARD LookupPrivilegeNameContainerConstIter end() const noexcept;

    private:
        LookupPrivilegeNameContainer lookupPrivilegeNames;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_BASE_H