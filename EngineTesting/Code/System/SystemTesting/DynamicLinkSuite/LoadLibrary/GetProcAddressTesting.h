///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.5 (2022/12/09 20:54)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        void GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule);
        void GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROC_ADDRESS_TESTING_H