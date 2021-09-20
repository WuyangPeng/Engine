///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/25 13:35)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_PROC_ADDRESS_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_PROC_ADDRESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetProcAddressTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetProcAddressTesting;
        using ParentType = UnitTest;

    public:
        explicit GetProcAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        void GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule);
        void GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule);
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_GET_PROC_ADDRESS_TESTING_H