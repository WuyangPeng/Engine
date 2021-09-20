///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/26 15:43)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H

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

        String GetResourcesLibrary() const;
        void FreeTestingLibrary();
        NODISCARD DynamicLinkModule GetDllModule() noexcept; 

    private:
        DynamicLinkModule m_DllModule;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TOOLS_TESTING_H