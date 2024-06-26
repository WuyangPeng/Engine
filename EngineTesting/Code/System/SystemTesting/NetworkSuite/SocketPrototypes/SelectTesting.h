/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/13 16:04)

#ifndef SYSTEM_NETWORK_SUITE_SELECT_TESTING_H
#define SYSTEM_NETWORK_SUITE_SELECT_TESTING_H

#include "SocketPrototypesTestingBase.h"
#include "System/Network/Using/SocketPrototypesUsing.h"

#include <mutex>

namespace System
{
    class SelectTesting final : public SocketPrototypesTestingBase
    {
    public:
        using ClassType = SelectTesting;
        using ParentType = SocketPrototypesTestingBase;

    public:
        explicit SelectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void SelectTest();

        void SelectThreadTest();

        void DoSelectTest(WinSocket socketHandle);
        void WinSockSetFdTest(WinSocket acceptHandle);
        NODISCARD WinSockInternetAddress AcceptInit(WinSocket socketHandle);
        NODISCARD WinSocket GetWinSocket(size_t index) const noexcept;
        void SelectSuccess(WinSockFdSet& readWinSockFdSet);
        void DoSelectSuccess(size_t index, WinSockFdSet& readWinSockFdSet);
        void WinSockFdClearTest(size_t index) noexcept;
        void RecvTest(size_t index);

    private:
        WinSockFdSet winSockFdSet;
        std::mutex mutex;
    };
}

#endif  // SYSTEM_NETWORK_SUITE_SELECT_TESTING_H