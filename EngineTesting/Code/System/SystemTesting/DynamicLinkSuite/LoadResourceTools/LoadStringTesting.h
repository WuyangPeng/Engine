///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.5 (2022/12/09 21:57)

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
        void DoRunUnitTest() final;
        void MainTest();

        void LoadStringTest();
    };
}

#endif  // SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H