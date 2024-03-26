/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:21)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H

#include "ResourceTestingBase.h"

namespace System
{
    /// @brief ������Դģ��Ĳ��ԡ�
    /// ����ֻ����dllModule������Ϊinstance�������
    /// SystemWindowsTesting��dllModuleΪinstanceʱ�Ĳ��ԡ�
    class FindResourceTesting final : public ResourceTestingBase
    {
    public:
        using ClassType = FindResourceTesting;
        using ParentType = ResourceTestingBase;

    public:
        explicit FindResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void FindResourceTest();
        void FindResourceUseLanguageTest();

        void DoFindResourceTest(const DynamicLinkCharType* type, WindowsWord name);
        void DoFindResourceUseLanguageTest(const DynamicLinkCharType* type, WindowsWord name);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_FIND_RESOURCE_TESTING_H