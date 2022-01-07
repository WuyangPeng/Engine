///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 19:53)

#ifndef CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H
#define CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H

#include "CoreTools/CoreToolsDll.h"

#include "XmlParser.h"
#include "CoreTools/TextParsing/TextParsingFwd.h"

namespace CoreTools
{
    namespace SimpleCSV
    {
        class XmlDataImpl;
        class XmlFileImpl;
        class SharedStringsImpl;

        class CommandSetSheetNameImpl;
        class CommandSetSheetVisibilityImpl;
        class CommandSetSheetColorImpl;
        class CommandSetSheetIndexImpl;
        class CommandAddWorksheetImpl;
        class CommandAddChartsheetImpl;
        class CommandDeleteSheetImpl;
        class CommandCloneSheetImpl;

        class QuerySheetNameImpl;
        class QuerySheetIndexImpl;
        class QuerySheetVisibilityImpl;
        class QuerySheetTypeImpl;
        class QuerySheetIDImpl;
        class QuerySheetRelsIDImpl;
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
}

#endif  // CORE_TOOLS_TEXT_PARSING_SIMPLE_CSV_INTERNAL_FWD_H