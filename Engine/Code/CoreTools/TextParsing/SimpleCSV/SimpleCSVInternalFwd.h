///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/03 20:18)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools::SimpleCSV
{
    class XmlDataImpl;
    class XmlFileImpl;
    class SharedStringsImpl;

    class CommandSetSheetNameImpl;
    class CommandSetSheetVisibilityImpl;
    class CommandSetSheetColorImpl;
    class CommandSetSheetIndexImpl;
    class CommandAddWorksheetImpl;
    class CommandAddChartSheetImpl;
    class CommandDeleteSheetImpl;
    class CommandCloneSheetImpl;

    class QuerySheetNameImpl;
    class QuerySheetIndexImpl;
    class QuerySheetVisibilityImpl;
    class QuerySheetTypeImpl;
    class QuerySheetIdImpl;
    class QuerySheetRelsIdImpl;
    class QuerySheetRelsTargetImpl;
    class QuerySharedStringsImpl;
    class QueryXmlDataImpl;

    class CellValueImpl;
    class CellReferenceImpl;
    class CellImpl;
    class CellValueProxyImpl;
    class CellRangeImpl;
    class CellIteratorImpl;
    class ColumnImpl;
    class RowDataIteratorImpl;
    class RowDataRangeImpl;
    class RowIteratorImpl;
    class RowRangeImpl;
    class RowDataProxyImpl;
    class RowImpl;
    class ContentItemImpl;
    class RelationshipItemImpl;
    class DocumentImpl;
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H