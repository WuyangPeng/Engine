///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 10:30)

#ifndef SYSTEM_NETWORK_SUITE_IOCTL_SOCKET_TESTING_H
#define SYSTEM_NETWORK_SUITE_IOCTL_SOCKET_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class IoctlSocketTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = IoctlSocketTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit IoctlSocketTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void IoctlSocketTest();

        void DoIoctlSocketTest(WinSocket socketHandle);
    };
}

#endif  // SYSTEM_NETWORK_SUITE_IOCTL_SOCKET_TESTING_H