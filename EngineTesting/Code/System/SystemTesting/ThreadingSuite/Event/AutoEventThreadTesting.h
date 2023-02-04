///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/31 23:10)

#ifndef SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H

#include "EventTestingBase.h"

namespace System
{
    class AutoEventThreadTesting final : public EventTestingBase
    {
    public:
        using ClassType = AutoEventThreadTesting;
        using ParentType = EventTestingBase;

    public:
        explicit AutoEventThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void AutoEventThreadTest();
        void DefaultEventThreadTest();
        void InitalSetEventThreadTest();

        void WaitForAutoEventTest(WindowsHandle eventHandle);
        void DoAutoEventThreadTest(WindowsHandle eventHandle);
        void DoDefaultEventThreadTest(WindowsHandle eventHandle);
        void DoInitalSetEventThreadTest(WindowsHandle eventHandle);

        void CreateThread(boost::thread_group& threadGroup, WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H