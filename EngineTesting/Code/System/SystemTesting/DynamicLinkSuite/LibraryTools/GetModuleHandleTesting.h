///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/25 20:01)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_HANDLE_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_HANDLE_TESTING_H

#include "System/DynamicLink/Fwd/DynamicLinkFlagsFwd.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetModuleHandleTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetModuleHandleTesting;
        using ParentType = UnitTest;

    public:
        explicit GetModuleHandleTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void GetModuleHandleSucceed0Test();
        void GetModuleHandleSucceed1Test();
        void GetModuleHandleSucceed2Test();
        void GetModuleHandleSucceed3Test();
        void GetModuleHandleFailureTest();

        NODISCARD DynamicLinkString GetResourcesLibraryName();
        NODISCARD DynamicLinkModule GetDynamicLibrary();
        NODISCARD DynamicLinkModule GetHandle();
        NODISCARD DynamicLinkModule GetHandle(GetModuleHandleType getModuleHandleType);
        void Destroy(DynamicLinkModule dynamicLinkModule);
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_MODULE_HANDLE_TESTING_H