///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.0 (2023/01/07 22:25)

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