///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.2 (2021/03/29 22:55)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class LoadResourceWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadResourceWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadResourceTest();

    private:
        using TypeNameContainer = std::map<WindowsWord, const DynamicLinkCharType*>;

    private:
        WindowsHInstance instance;
        TypeNameContainer container;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_WINDOWS_TESTING_H