///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/19 13:40)

#ifndef CORE_TOOLS_TEXT_PARSING_FWD_H
#define CORE_TOOLS_TEXT_PARSING_FWD_H

namespace CoreTools
{
    namespace SimpleZip
    {
        class ZipEntry;
        class ZipArchive;
    }

    namespace SimpleCSV
    {
        enum class CSVExceptionType;
        enum class ContentType;
        enum class SheetState;
        enum class ValueType;
        enum class IteratorDirection;
        enum class IteratorLocation;
        enum class RelationshipType;
        enum class SheetType;
        enum class Property;

        class CommandSetSheetName;
        class CommandSetSheetVisibility;
        class CommandSetSheetColor;
        class CommandSetSheetIndex;
        class CommandResetCalcChain;
        class CommandAddSharedStrings;
        class CommandAddWorksheet;
        class CommandAddChartsheet;
        class CommandDeleteSheet;
        class CommandCloneSheet;

        class QuerySheetName;
        class QuerySheetIndex;
        class QuerySheetVisibility;
        class QuerySheetType;
        class QuerySheetID;
        class QuerySheetRelsID;
        class QuerySheetRelsTarget;
        class QuerySharedStrings;
        class QueryXmlData;

        class SimpleCSVException;
        class XmlData;
        class XmlFile;
        class SharedStrings;
        class Color;
        class CellValueProxy;
        class CellValue;
        class CellReference;
        class Cell;
        class CellRange;
        class CellIterator;
        class Column;
        class RowDataIterator;
        class RowDataRange;
        class RowRange;
        class RowIterator;
        class Row;
        class RowDataProxy;
        class SheetBase;
        class Worksheet;
        class AppProperties;
        class Properties;
        class ContentItem;
        class ContentTypes;
        class RelationshipItem;
        class Relationships;
        class Workbook;
        class Document;
    }

    enum class CSVType;
    enum class CSVFormatType;
    enum class CSVDataType;
    enum class CSVGenerateType;
    enum class CSVTotalGenerateType;
    enum class CSVPoistionType;

    class Vector2;
    class Vector3;
    class Vector4;
    class IntVector2;
    class IntVector3;
    class IntVector4;

    class ExcelConversionCSV;
    class BatchConversionCSV;
    class CSVTypeConversion;
    class CSVHead;
    class CSVRow;
    class CSVContent;
    class DataTypeDescribe;

    class CSVGenerate;
    class CSVTotalGenerate;

    enum class JsonDataType;
    enum class JsonGenerateType;
    enum class JsonTotalGenerateType;

    class JsonHead;
    class JsonNode;
    class JsonNodeContainer;

    class JsonGenerate;
    class JsonRow;
}

#endif  // CORE_TOOLS_TEXT_PARSING_FWD_H