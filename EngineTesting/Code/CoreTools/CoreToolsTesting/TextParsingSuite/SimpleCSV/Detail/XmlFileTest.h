///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:14)

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

        NODISCARD std::string GetRelationshipIDByXmlFile() const;

        NODISCARD DocumentSharedPtr GetParentDocumentByXmlFile();
        NODISCARD ConstDocumentSharedPtr GetParentDocumentByXmlFile() const;
        NODISCARD SimpleCSV::XMLDocumentSharedPtr GetXmlDocumentByXmlFile();
        NODISCARD SimpleCSV::ConstXMLDocumentSharedPtr GetXmlDocumentByXmlFile() const;
    };
}

#endif  // CORE_TOOLS_TEXT_PARSING_SUITE_XML_FILE_TEST_H
