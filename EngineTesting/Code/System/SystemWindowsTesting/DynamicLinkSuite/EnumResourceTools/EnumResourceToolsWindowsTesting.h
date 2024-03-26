/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:38)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H

#include "EnumResourceToolsTesting.h"

namespace System
{
    /// @brief 枚举资源工具模块的测试。
    /// 这里只测试dllModule参数为instance的情况。
    /// SystemTesting有dllModule不为instance时的测试。
    class EnumResourceToolsWindowsTesting final : public EnumResourceToolsTesting
    {
    public:
        using ClassType = EnumResourceToolsWindowsTesting;
        using ParentType = EnumResourceToolsTesting;

    public:
        explicit EnumResourceToolsWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void EnumResourceTest() override;
        void EnumResourceExistTest(const EnumResourceData& data) override;

    private:
        WindowsHInstance instance;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H