///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:38)

#ifndef CORE_TOOLS_TEXT_PARSING_UTILITIES_H
#define CORE_TOOLS_TEXT_PARSING_UTILITIES_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/TextParsing/SimpleCSV/CellReference.h"
#include "CoreTools/TextParsing/SimpleCSV/XmlParser.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        NODISCARD XMLNode CORE_TOOLS_HIDDEN_DECLARE GetRowNode(XMLNode sheetDataNode, int rowNumber);
        NODISCARD XMLNode CORE_TOOLS_HIDDEN_DECLARE GetCellNode(XMLNode rowNode, int columnNumber);
        NODISCARD std::string CORE_TOOLS_HIDDEN_DECLARE GetLastChildAttributeR(const XMLNode& rowNode);
        NODISCARD std::string CORE_TOOLS_HIDDEN_DECLARE GetAttributeR(const XMLNode& rowNode);
        NODISCARD int CORE_TOOLS_HIDDEN_DECLARE GetAttributeMin(const XMLNode& columnNode);
        NODISCARD int CORE_TOOLS_HIDDEN_DECLARE GetAttributeMax(const XMLNode& columnNode);
        NODISCARD int CORE_TOOLS_HIDDEN_DECLARE GetColumnNumber(const XMLNode& rowNode);
    }
}

#endif  // CORE_TOOLS_TEXT_PARSING_UTILITIES_H
