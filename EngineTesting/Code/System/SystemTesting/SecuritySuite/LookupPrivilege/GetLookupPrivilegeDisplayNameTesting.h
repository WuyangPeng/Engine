///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/25 11:51)

#ifndef SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_DISPLAY_NAME_TESTING_H
#define SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_DISPLAY_NAME_TESTING_H

#include "LookupPrivilegeTestingBase.h"

namespace System
{
    class GetLookupPrivilegeDisplayNameTesting final : public LookupPrivilegeTestingBase
    {
    public:
        using ClassType = GetLookupPrivilegeDisplayNameTesting;
        using ParentType = LookupPrivilegeTestingBase;

    public:
        explicit GetLookupPrivilegeDisplayNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetLookupPrivilegeDisplayNameTest();

        void DoGetLookupPrivilegeDisplayNameTest(const String& lookupPrivilegeName);
    };
}

#endif  // SYSTEM_SECURITY_SUITE_GET_LOOKUP_PRIVILEGE_DISPLAY_NAME_TESTING_H