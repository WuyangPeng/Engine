///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/19 19:55)

#ifndef CORE_TOOLS_TEXT_PARSING_XML_PARSER_H
#define CORE_TOOLS_TEXT_PARSING_XML_PARSER_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>

namespace pugi
{
    class xml_node;
    class xml_attribute;
    class xml_document;
}

namespace CoreTools
{
    namespace SimpleCSV
    {
        // xml_node����������������xml_document��
        using XMLNode = pugi::xml_node;
        using XMLAttribute = pugi::xml_attribute;
        using XMLDocument = pugi::xml_document;

        using XMLDocumentSharedPtr = std::shared_ptr<XMLDocument>;
        using ConstXMLDocumentSharedPtr = std::shared_ptr<const XMLDocument>;
        using XMLDocumentWeakPtr = std::weak_ptr<XMLDocument>;
        using ConstXMLDocumentWeakPtr = std::weak_ptr<const XMLDocument>;
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_XML_PARSER_H
