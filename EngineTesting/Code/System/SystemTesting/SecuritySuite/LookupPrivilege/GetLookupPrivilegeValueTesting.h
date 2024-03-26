/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 13:22)

#ifndef SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_VALUE_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_VALUE_TESTING_H

#include "LookupPrivilegeTestingBase.h"

namespace System
{
    class GetLookupPrivilegeValueTesting final : public LookupPrivilegeTestingBase
    {
    public:
        using ClassType = GetLookupPrivilegeValueTesting;
        using ParentType = LookupPrivilegeTestingBase;

    public:
        explicit GetLookupPrivilegeValueTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetLookupPrivilegeValueTest();

        void DoGetLookupPrivilegeValueTesting(const String& lookupPrivilegeName);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_VALUE_TESTING_H