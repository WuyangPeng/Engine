///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.2 (2021/03/29 16:38)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_TESTING_H

#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

#include <map>

namespace System
{
    class FindResourceTesting final : public LoadResourceToolsTesting
    {
    public:
        using ClassType = FindResourceTesting;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit FindResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void FindResourceTest();
        void FindResourceUseLanguageTest();

    private:
        using TypeNameContainer = std::map<WindowsWord, const DynamicLinkCharType*>;

    private:
        TypeNameContainer container;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_FIND_RESOURCE_TESTING_H