/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 16:47)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ContentItemTesting final : public UnitTest
    {
    public:
        using ClassType = ContentItemTesting;
        using ParentType = UnitTest;

    public:
        explicit ContentItemTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using ContentItem = SimpleCSV::ContentItem;
        using ContentType = SimpleCSV::ContentType;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ContentItemTest();
        void TypeStringTest();

        void DoContentItemTest(const ContentItem& item);
        void ContentTypeTest(const ContentItem& item);
        void WorksheetTest(const ContentItem& item);
        void ThemeTest(const ContentItem& item);
        void StylesTest(const ContentItem& item);
        void SharedStringsTest(const ContentItem& item);
        void CorePropertiesTest(const ContentItem& item);
        void ExtendedPropertiesTest(const ContentItem& item);
        void CustomPropertiesTest(const ContentItem& item);
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_CONTENT_ITEM_TESTING_H