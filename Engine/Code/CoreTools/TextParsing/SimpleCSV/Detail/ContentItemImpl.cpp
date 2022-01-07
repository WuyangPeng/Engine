///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 21:24)

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

CoreTools::SimpleCSV::ContentItemImpl::StringFromTypeContent CoreTools::SimpleCSV::ContentItemImpl::GetStringFromTypeContent()
{
    const StringFromTypeContent stringFromTypeContent{ { ContentType::WorkbookMacroEnabled, "application/vnd.ms-excel.Sheet.macroEnabled.main+xml"s },
                                                       { ContentType::Workbook, "application/vnd.openxmlformats-officedocument.spreadsheetml.sheet.main+xml"s },
                                                       { ContentType::Worksheet, "application/vnd.openxmlformats-officedocument.spreadsheetml.worksheet+xml"s },
                                                       { ContentType::Chartsheet, "application/vnd.openxmlformats-officedocument.spreadsheetml.chartsheet+xml"s },
                                                       { ContentType::ExternalLink, "application/vnd.openxmlformats-officedocument.spreadsheetml.externalLink+xml"s },
                                                       { ContentType::Theme, "application/vnd.openxmlformats-officedocument.theme+xml"s },
                                                       { ContentType::Styles, "application/vnd.openxmlformats-officedocument.spreadsheetml.styles+xml"s },
                                                       { ContentType::SharedStrings, "application/vnd.openxmlformats-officedocument.spreadsheetml.sharedStrings+xml"s },
                                                       { ContentType::Drawing, "application/vnd.openxmlformats-officedocument.drawing+xml"s },
                                                       { ContentType::Chart, "application/vnd.openxmlformats-officedocument.drawingml.chart+xml"s },
                                                       { ContentType::ChartStyle, "application/vnd.ms-office.chartstyle+xml"s },
                                                       { ContentType::ChartColorStyle, "application/vnd.ms-office.chartcolorstyle+xml"s },
                                                       { ContentType::ControlProperties, "application/vnd.ms-excel.controlproperties+xml"s },
                                                       { ContentType::CalculationChain, "application/vnd.openxmlformats-officedocument.spreadsheetml.calcChain+xml"s },
                                                       { ContentType::VBAProject, "application/vnd.ms-office.vbaProject"s },
                                                       { ContentType::CoreProperties, "application/vnd.openxmlformats-package.core-properties+xml"s },
                                                       { ContentType::ExtendedProperties, "application/vnd.openxmlformats-officedocument.extended-properties+xml"s },
                                                       { ContentType::CustomProperties, "application/vnd.openxmlformats-officedocument.custom-properties+xml"s },
                                                       { ContentType::Comments, "application/vnd.openxmlformats-officedocument.spreadsheetml.comments+xml"s },
                                                       { ContentType::Table, "application/vnd.openxmlformats-officedocument.spreadsheetml.table+xml"s },
                                                       { ContentType::VMLDrawing, "application/vnd.openxmlformats-officedocument.vmlDrawing"s } };

    return stringFromTypeContent;
}

CoreTools::SimpleCSV::ContentItemImpl::TypeFromStringContent CoreTools::SimpleCSV::ContentItemImpl::GetTypeFromStringContent()
{
    const auto stringFromTypeContent = GetStringFromTypeContent();

    TypeFromStringContent typeFromStringContent{};

    for (const auto& value : stringFromTypeContent)
    {
        typeFromStringContent.emplace(value.second, value.first);
    }

    return typeFromStringContent;
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::ContentItemImpl::GetTypeFromString(const string& typeString)
{
    static const auto typeFromStringContent = GetTypeFromStringContent();

    const auto iter = typeFromStringContent.find(typeString);

    if (iter != typeFromStringContent.cend())
    {
        return iter->second;
    }

    return ContentType::Unknown;
}

string CoreTools::SimpleCSV::ContentItemImpl::GetStringFromType(ContentType type)
{
    static const auto stringFromTypeConten = GetStringFromTypeContent();

    const auto iter = stringFromTypeConten.find(type);

    if (iter != stringFromTypeConten.cend())
    {
        return iter->second;
    }

    return string{};
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
