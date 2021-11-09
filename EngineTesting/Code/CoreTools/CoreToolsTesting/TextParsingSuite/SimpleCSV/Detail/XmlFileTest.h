///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.4 (2021/10/04 20:52)

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
