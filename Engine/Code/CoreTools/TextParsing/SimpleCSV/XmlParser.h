///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 20:18)

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

namespace CoreTools::SimpleCSV
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

#endif  // CORE_TOOLS_TEXT_PARSING_XML_PARSER_H
