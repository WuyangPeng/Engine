/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 16:48)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ContentTypesTesting final : public UnitTest
    {
    public:
        using ClassType = ContentTypesTesting;
        using ParentType = UnitTest;

    public:
        explicit ContentTypesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ContentTypes = SimpleCSV::ContentTypes;
        using ContentItem = SimpleCSV::ContentItem;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ContentTypesTest();

        void GetContentItemTest(const ContentTypes& contentTypes, const ContentItem& item);
        void OverrideTest(ContentTypes& contentTypes);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_TYPES_TESTING_H