/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:05)

#ifndef SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H
#define SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H

#include "SocketPrototypesTestingBase.h"

namespace System
{
    class SendToTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = SendToTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit SendToTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SendToTest();

        void DoSendToTest(WinSocket socketHandle) const;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SEND_TO_TESTING_H