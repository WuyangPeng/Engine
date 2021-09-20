///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.4 (2021/06/05 15:23)

#ifndef SYSTEM_SECURITY_SUITE_HOST_NET_CONVERSION_TESTING_H
#define SYSTEM_SECURITY_SUITE_HOST_NET_CONVERSION_TESTING_H

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

#endif  // SYSTEM_SECURITY_SUITE_HOST_NET_CONVERSION_TESTING_H