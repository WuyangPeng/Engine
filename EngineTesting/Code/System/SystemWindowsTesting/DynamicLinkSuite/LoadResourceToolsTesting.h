///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/08 20:36)

/// ԭʼ�ļ���SystemTesting�£�SystemWindowsTesting�µ�Ϊ�Զ������ļ��������޸ġ�
#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class LoadResourceToolsTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadResourceToolsTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadResourceToolsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        void LoadTestingLibrary();

        NODISCARD String GetResourcesLibrary() const;
        void FreeTestingLibrary();
        NODISCARD DynamicLinkModule GetDllModule() noexcept;

    private:
        DynamicLinkModule dllModule;
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H