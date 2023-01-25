///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.0 (2023/01/07 22:25)

#ifndef SYSTEM_NETWORK_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H
#define SYSTEM_NETWORK_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H

#include "NetworkTestingBase.h"

namespace System
{
    class WindowsExtensionPrototypesTesting final : public NetworkTestingBase
    {
    public:
        using ClassType = WindowsExtensionPrototypesTesting;
        using ParentType = NetworkTestingBase;

    public:
        explicit WindowsExtensionPrototypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WinSockLastErrorTest();
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H