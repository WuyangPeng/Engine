///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/10 14:41)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H

#include "EnumResourceToolsTesting.h"

namespace System
{
    class EnumResourceToolsWindowsTesting final : public EnumResourceToolsTesting
    {
    public:
        using ClassType = EnumResourceToolsWindowsTesting;
        using ParentType = EnumResourceToolsTesting;

    public:
        explicit EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void EnumResourceTest() final;
        void EnumResourceExistTest(const EnumResourceData& data) final;

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H