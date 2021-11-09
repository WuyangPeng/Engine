///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/13 19:17)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/CSVExceptionFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/Flags/RelationshipFlags.h"
#include "CoreTools/TextParsing/SimpleCSV/SimpleCSVException.h"

using std::string;
using namespace std::literals;

CoreTools::SimpleCSV::RelationshipItemImpl::RelationshipItemImpl(const ConstXMLDocumentSharedPtr& document, const XMLNode& node) noexcept
    : document{ document }, relationshipNode{ node }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, RelationshipItemImpl);

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItemImpl::GetTypeFromString(const string& typeString)
{
    auto type = RelationshipType::Unknown;

    if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties"s)
        type = RelationshipType::ExtendedProperties;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/custom-properties"s)
        type = RelationshipType::CustomProperties;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"s)
        type = RelationshipType::Workbook;
    else if (typeString == "http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties"s)
        type = RelationshipType::CoreProperties;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet"s)
        type = RelationshipType::Worksheet;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles"s)
        type = RelationshipType::Styles;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sharedStrings"s)
        type = RelationshipType::SharedStrings;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/calcChain"s)
        type = RelationshipType::CalculationChain;
    else if (typeString == "http://schemas.microsoft.com/office/2006/relationships/vbaProject"s)
        type = RelationshipType::VBAProject;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLink"s)
        type = RelationshipType::ExternalLink;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/theme"s)
        type = RelationshipType::Theme;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chartsheet"s)
        type = RelationshipType::Chartsheet;
    else if (typeString == "http://schemas.microsoft.com/office/2011/relationships/chartStyle"s)
        type = RelationshipType::ChartStyle;
    else if (typeString == "http://schemas.microsoft.com/office/2011/relationships/chartColorStyle"s)
        type = RelationshipType::ChartColorStyle;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing"s)
        type = RelationshipType::Drawing;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/image"s)
        type = RelationshipType::Image;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chart"s)
        type = RelationshipType::Chart;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLinkPath"s)
        type = RelationshipType::ExternalLinkPath;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/printerSettings"s)
        type = RelationshipType::PrinterSettings;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/vmlDrawing"s)
        type = RelationshipType::VMLDrawing;
    else if (typeString == "http://schemas.openxmlformats.org/officeDocument/2006/relationships/ctrlProp"s)
        type = RelationshipType::ControlProperties;
    else
        type = RelationshipType::Unknown;

    return type;
}

string CoreTools::SimpleCSV::RelationshipItemImpl::GetStringFromType(RelationshipType type)
{
    string typeString{};

    if (type == RelationshipType::ExtendedProperties)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties"s;
    }
    else if (type == RelationshipType::CustomProperties)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/custom-properties"s;
    }
    else if (type == RelationshipType::Workbook)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"s;
    }
    else if (type == RelationshipType::CoreProperties)
    {
        typeString = "http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties"s;
    }
    else if (type == RelationshipType::Worksheet)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet"s;
    }
    else if (type == RelationshipType::Styles)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles"s;
    }
    else if (type == RelationshipType::SharedStrings)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sharedStrings"s;
    }
    else if (type == RelationshipType::CalculationChain)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/calcChain"s;
    }
    else if (type == RelationshipType::VBAProject)
    {
        typeString = "http://schemas.microsoft.com/office/2006/relationships/vbaProject"s;
    }
    else if (type == RelationshipType::ExternalLink)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLink"s;
    }
    else if (type == RelationshipType::Theme)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/theme"s;
    }
    else if (type == RelationshipType::Chartsheet)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chartsheet"s;
    }
    else if (type == RelationshipType::ChartStyle)
    {
        typeString = "http://schemas.microsoft.com/office/2011/relationships/chartStyle"s;
    }
    else if (type == RelationshipType::ChartColorStyle)
    {
        typeString = "http://schemas.microsoft.com/office/2011/relationships/chartColorStyle"s;
    }
    else if (type == RelationshipType::Drawing)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing"s;
    }
    else if (type == RelationshipType::Image)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/image"s;
    }
    else if (type == RelationshipType::Chart)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chart"s;
    }
    else if (type == RelationshipType::ExternalLinkPath)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLinkPath"s;
    }
    else if (type == RelationshipType::PrinterSettings)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/printerSettings"s;
    }
    else if (type == RelationshipType::VMLDrawing)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/vmlDrawing"s;
    }
    else if (type == RelationshipType::ControlProperties)
    {
        typeString = "http://schemas.openxmlformats.org/officeDocument/2006/relationships/ctrlProp"s;
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, "无法识别关系类型！"s);
    }

    return typeString;
}

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItemImpl::GetType() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetTypeFromString(relationshipNode.attribute("Type").value());
}

string CoreTools::SimpleCSV::RelationshipItemImpl::GetTarget() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return relationshipNode.attribute(TextParsing::g_Target.data()).value();
}

string CoreTools::SimpleCSV::RelationshipItemImpl::GetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document已被释放。"s));
    }

    return relationshipNode.attribute(TextParsing::g_ID.data()).value();
}
