///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.4 (2021/05/27 11:51)

#ifndef SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_H
#define SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class LookupPrivilegeTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LookupPrivilegeTesting;
        using ParentType = UnitTest;

    public:
        explicit LookupPrivilegeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetLookupPrivilegeTest();

    private:
        using LookupPrivilegeNameCollection = std::vector<String>;

    private:
        LookupPrivilegeNameCollection lookupPrivilegeNameCollection;
    };
}

#endif  // SYSTEM_SECURITY_SUITE_LOOKUP_PRIVILEGE_TESTING_H