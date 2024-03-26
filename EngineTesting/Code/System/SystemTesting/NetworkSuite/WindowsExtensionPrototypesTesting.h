/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:06)

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
        void DoRunUnitTest() override;
        void MainTest();

        void WinSockLastErrorTest();
    };
}

#endif  // SYSTEM_NETWORK_SUITE_WINDOWS_EXTENSION_PROTOTYPES_TESTING_H