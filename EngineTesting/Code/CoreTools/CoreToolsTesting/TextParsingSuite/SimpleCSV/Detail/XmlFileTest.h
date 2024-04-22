/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/17 10:32)

#ifndef CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TEST_H
#define CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TEST_H

#include "CoreTools/TextParsing/SimpleCSV/XmlFile.h"

namespace CoreTools
{
    class XmlFileTest final : public SimpleCSV::XmlFile
    {
    public:
        using ClassType = XmlFileTest;
        using ParentType = XmlFile;

    public:
        explicit XmlFileTest(const XmlDataSharedPtr& xmlData);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD std::string GetXmlDataByXmlFile() const;

        void SetXmlDataByXmlFile(const std::string& data);

        NODISCARD std::string GetRelationshipIdByXmlFile() const;

        NODISCARD DocumentSharedPtr GetParentDocumentByXmlFile();
        NODISCARD ConstDocumentSharedPtr GetParentDocumentByXmlFile() const;
        NODISCARD SimpleCSV::XMLDocumentSharedPtr GetXmlDocumentByXmlFile();
        NODISCARD SimpleCSV::ConstXMLDocumentSharedPtr GetXmlDocumentByXmlFile() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TEST_H
