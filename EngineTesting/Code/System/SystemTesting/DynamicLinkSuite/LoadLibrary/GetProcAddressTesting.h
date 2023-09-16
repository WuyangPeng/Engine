///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:00)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROC_ADDRESS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROC_ADDRESS_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        void GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule);
        void GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROC_ADDRESS_TESTING_H