///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/10 14:41)

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