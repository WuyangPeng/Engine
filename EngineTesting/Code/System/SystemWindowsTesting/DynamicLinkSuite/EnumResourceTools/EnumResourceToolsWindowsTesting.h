/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:38)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_ENUM_RESOURCE_TOOLS_WINDOWS_TESTING_H

#include "EnumResourceToolsTesting.h"

namespace System
{
    /// @brief ö����Դ����ģ��Ĳ��ԡ�
    /// ����ֻ����dllModule����Ϊinstance�������
    /// SystemTesting��dllModule��Ϊinstanceʱ�Ĳ��ԡ�
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