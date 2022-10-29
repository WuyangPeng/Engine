///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/09 22:26)

#ifndef SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_WINDOWS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_WINDOWS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <map>

namespace System
{
    class FindResourceWindowsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = FindResourceWindowsTesting;
        using ParentType = UnitTest;

    public:
        explicit FindResourceWindowsTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FindResourceTest();
        void FindResourceUseLanguageTest();

    private:
        using TypeNameContainer = std::map<WindowsWord, const DynamicLinkCharType*>;

    private:
        WindowsHInstance instance;
        TypeNameContainer container;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_WINDOWS_TESTING_H