///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:27)

#ifndef SYSTEM_THREADING_SUITE_CREATE_EVENT_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_EVENT_USE_NAME_TESTING_H

#include "EventTestingBase.h"

namespace System
{
    class CreateEventUseNameTesting final : public EventTestingBase
    {
    public:
        using ClassType = CreateEventUseNameTesting;
        using ParentType = EventTestingBase;

    public:
        explicit CreateEventUseNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void CreateEventTest(bool manualReset, bool initialState);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_EVENT_USE_NAME_TESTING_H