///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/12 12:07)

#ifndef SYSTEM_NETWORK_SUITE_WIN_SOCKET_HOST_NET_CONVERSION_TESTING_H
#define SYSTEM_NETWORK_SUITE_WIN_SOCKET_HOST_NET_CONVERSION_TESTING_H

#include "WindowsSockExTestingBase.h"

namespace System
{
    class WinSocketHostNetConversionTesting final : public WindowsSockExTestingBase
    {
    public:
        using ClassType = WinSocketHostNetConversionTesting;
        using ParentType = WindowsSockExTestingBase;

    public:
        explicit WinSocketHostNetConversionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ShortTest();
        void LongTest();

        void DoShortTest(WinSocket socketHandle);
        void DoLongTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WIN_SOCKET_HOST_NET_CONVERSION_TESTING_H