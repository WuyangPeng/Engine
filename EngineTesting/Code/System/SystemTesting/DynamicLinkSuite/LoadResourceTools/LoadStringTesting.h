///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/08/31 17:01)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H

#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

namespace System
{
    class LoadStringTesting final : public LoadResourceToolsTesting
    {
    public:
        using ClassType = LoadStringTesting;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit LoadStringTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void LoadStringTest();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H