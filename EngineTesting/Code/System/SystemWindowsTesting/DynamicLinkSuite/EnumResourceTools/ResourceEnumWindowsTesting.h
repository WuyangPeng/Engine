///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/09 22:24)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H

#include "ResourceEnumTesting.h"

namespace System
{
    class ResourceEnumWindowsTesting final : public ResourceEnumTesting
    {
    public:
        using ClassType = ResourceEnumWindowsTesting;
        using ParentType = ResourceEnumTesting;

    public:
        explicit ResourceEnumWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoEnumResourceTest() override;
        void EnumResourceExistTest(const EnumResourceData& data) override;

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H