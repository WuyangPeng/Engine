/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:38)

#ifndef SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_DYNAMIC_LINK_SUITE_RESOURCE_ENUM_WINDOWS_TESTING_H

#include "ResourceEnumTesting.h"

namespace System
{
    // @brief ��Դö��ģ��Ĳ��ԡ�
    /// ����ֻ����dllModule����Ϊinstance�������
    /// SystemWindowsTesting��dllModule��Ϊinstanceʱ�Ĳ��ԡ�
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