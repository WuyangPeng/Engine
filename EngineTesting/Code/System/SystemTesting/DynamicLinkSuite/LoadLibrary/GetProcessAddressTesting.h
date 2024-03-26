/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/09 21:21)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROCESS_ADDRESS_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROCESS_ADDRESS_TESTING_H

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetProcessAddressTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetProcessAddressTesting;
        using ParentType = UnitTest;

    public:
        explicit GetProcessAddressTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD static DynamicLinkModule GetDynamicLibrary();
        void Destroy(DynamicLinkModule dynamicLinkModule);

        void GetProcAddressSucceedTest(DynamicLinkModule dynamicLinkModule);
        void GetProcAddressFailureTest(DynamicLinkModule dynamicLinkModule);
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_GET_PROCESS_ADDRESS_TESTING_H