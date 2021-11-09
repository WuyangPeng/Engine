///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/13 18:30)

#include "CoreTools/CoreToolsExport.h"

#include "ContentItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/ContentFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;
using namespace std::literals;

CoreTools::SimpleCSV::ContentItemImpl::ContentItemImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& node) noexcept
    : document{ document }, contentNode{ node }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, ContentItemImpl)

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItemImpl::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return GetTypeFromString(contentNode.attribute("ContentType").value());
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItemImpl::GetTypeFromString(const string& typeString)
{
    auto type = ContentType::Unknown;

    if (typeString == "application/vnd.ms-excel.Sheet.macroEnabled.main+xml"s)
        type = ContentType::WorkbookMacroEnabled;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"s)
        type = ContentType::Workbook;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"s)
        type = ContentType::Worksheet;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml"s)
        type = ContentType::Chartsheet;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml"s)
        type = ContentType::ExternalLink;
    else if (typeString == "application/vnd.openxmlformats-officedocument.theme+xml"s)
        type = ContentType::Theme;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"s)
        type = ContentType::Styles;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml"s)
        type = ContentType::SharedStrings;
    else if (typeString == "application/vnd.openxmlformats-officedocument.drawing+xml"s)
        type = ContentType::Drawing;
    else if (typeString == "application/vnd.openxmlformats-officedocument.drawingml.chart+xml"s)
        type = ContentType::Chart;
    else if (typeString == "application/vnd.ms-office.chartstyle+xml"s)
        type = ContentType::ChartStyle;
    else if (typeString == "application/vnd.ms-office.chartcolorstyle+xml"s)
        type = ContentType::ChartColorStyle;
    else if (typeString == "application/vnd.ms-excel.controlproperties+xml"s)
        type = ContentType::ControlProperties;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml"s)
        type = ContentType::CalculationChain;
    else if (typeString == "application/vnd.ms-office.vbaProject"s)
        type = ContentType::VBAProject;
    else if (typeString == "application/vnd.openxmlformats-package.core-properties+xml"s)
        type = ContentType::CoreProperties;
    else if (typeString == "application/vnd.openxmlformats-officedocument.extended-properties+xml"s)
        type = ContentType::ExtendedProperties;
    else if (typeString == "application/vnd.openxmlformats-officedocument.custom-properties+xml"s)
        type = ContentType::CustomProperties;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml"s)
        type = ContentType::Comments;
    else if (typeString == "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml"s)
        type = ContentType::Table;
    else if (typeString == "application/vnd.openxmlformats-officedocument.vmlDrawing"s)
        type = ContentType::VMLDrawing;
    else
        type = ContentType::Unknown;

    return type;
}

string CoreTools::SimpleCSV::ContentItemImpl::GetStringFromType(ContentType type)
{
    string typeString{};

    if (type == ContentType::WorkbookMacroEnabled)
    {
        typeString = "application/vnd.ms-excel.Sheet.macroEnabled.main+xml"s;
    }
    else if (type == ContentType::Workbook)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"s;
    }
    else if (type == ContentType::Worksheet)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"s;
    }
    else if (type == ContentType::Chartsheet)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml"s;
    }
    else if (type == ContentType::ExternalLink)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml"s;
    }
    else if (type == ContentType::Theme)
    {
        typeString = "application/vnd.openxmlformats-officedocument.theme+xml"s;
    }
    else if (type == ContentType::Styles)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"s;
    }
    else if (type == ContentType::SharedStrings)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml"s;
    }
    else if (type == ContentType::Drawing)
    {
        typeString = "application/vnd.openxmlformats-officedocument.drawing+xml"s;
    }
    else if (type == ContentType::Chart)
    {
        typeString = "application/vnd.openxmlformats-officedocument.drawingml.chart+xml"s;
    }
    else if (type == ContentType::ChartStyle)
    {
        typeString = "application/vnd.ms-office.chartstyle+xml"s;
    }
    else if (type == ContentType::ChartColorStyle)
    {
        typeString = "application/vnd.ms-office.chartcolorstyle+xml"s;
    }
    else if (type == ContentType::ControlProperties)
    {
        typeString = "application/vnd.ms-excel.controlproperties+xml"s;
    }
    else if (type == ContentType::CalculationChain)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml"s;
    }
    else if (type == ContentType::VBAProject)
    {
        typeString = "application/vnd.ms-office.vbaProject"s;
    }
    else if (type == ContentType::CoreProperties)
    {
        typeString = "application/vnd.openxmlformats-package.core-properties+xml"s;
    }
    else if (type == ContentType::ExtendedProperties)
    {
        typeString = "application/vnd.openxmlformats-officedocument.extended-properties+xml"s;
    }
    else if (type == ContentType::CustomProperties)
    {
        typeString = "application/vnd.openxmlformats-officedocument.custom-properties+xml"s;
    }
    else if (type == ContentType::Comments)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml"s;
    }
    else if (type == ContentType::Table)
    {
        typeString = "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml"s;
    }
    else if (type == ContentType::VMLDrawing)
    {
        typeString = "application/vnd.openxmlformats-officedocument.vmlDrawing"s;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, "未知ContentType"s);
    }

    return typeString;
}

string CoreTools::SimpleCSV::ContentItemImpl::GetPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return contentNode.attribute("PartName").value();
}
