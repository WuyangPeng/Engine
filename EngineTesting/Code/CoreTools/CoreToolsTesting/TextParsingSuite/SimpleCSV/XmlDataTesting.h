/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/17 17:11)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H

#include "CoreTools/TextParsing/SimpleCSV/Document.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class XmlDataTesting final : public UnitTest
    {
    public:
        using ClassType = XmlDataTesting;
        using ParentType = UnitTest;

    public:
        explicit XmlDataTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Document = SimpleCSV::Document;
        using XmlData = SimpleCSV::XmlData;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void XmlDataTest();
        void ConstXmlDataTest();

        void XmlData0Test(Document& document, XmlData& xmlData);
        void XmlData1Test(const XmlData& xmlData);

    private:
        static constexpr auto contentType = SimpleCSV::ContentType::ChartSheet;

        std::string xmlPath;
        std::string xmlId;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_DATA_TESTING_H
