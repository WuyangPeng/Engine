/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/09 21:20)

#ifndef SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H
#define SYSTEM_TESTING_DYNAMIC_LINK_SUITE_LOAD_STRING_TESTING_H

#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

namespace System
{
    /// @brief 加载字符串模块的测试。
    /// 这里只测试dllModule参数不为instance的情况。
    /// SystemWindowsTesting有dllModule为instance时的测试。
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