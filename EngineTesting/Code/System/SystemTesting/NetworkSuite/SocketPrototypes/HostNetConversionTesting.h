///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/10 0:24)

#ifndef SYSTEM_NETWORK_SUITE_HOST_NET_CONVERSION_TESTING_H
#define SYSTEM_NETWORK_SUITE_HOST_NET_CONVERSION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class HostNetConversionTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = HostNetConversionTesting;
        using ParentType = UnitTest;

    public:
        explicit HostNetConversionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ShortTest();
        void LongTest();
    };
}

#endif  // SYSTEM_NETWORK_SUITE_HOST_NET_CONVERSION_TESTING_H