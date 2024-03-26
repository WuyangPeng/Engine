/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 17:57)

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