///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.2 (2021/03/29 22:55)

#ifndef SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TESTING_H
#define SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TESTING_H

#include "System/SystemTesting/DynamicLinkSuite/LoadResourceToolsTesting.h"

#include <map>

namespace System
{
    class LoadResourceTesting final : public LoadResourceToolsTesting
    {
    public:
        using ClassType = LoadResourceTesting;
        using ParentType = LoadResourceToolsTesting;

    public:
        explicit LoadResourceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void LoadResourceTest();

    private:
        using TypeNameContainer = std::map<WindowsWord, const DynamicLinkCharType*>;

    private:
        TypeNameContainer container;
    };
}

#endif  // SYSTEM_TESTING_SYSTEM_OUTPUT_SUITE_LOAD_RESOURCE_TESTING_H