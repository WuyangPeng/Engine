///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/20 22:12)

#include "CoreTools/CoreToolsExport.h"

#include "RelationshipItemImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"
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

CoreTools::SimpleCSV::RelationshipItemImpl::TypeFromStringRelationship CoreTools::SimpleCSV::RelationshipItemImpl::GetTypeFromStringRelationship()
{
    const auto stringFromTypeRelationship = GetStringFromTypeRelationship();

    TypeFromStringRelationship typeFromStringRelationship{};

    for (const auto& value : stringFromTypeRelationship)
    {
        typeFromStringRelationship.emplace(value.second, value.first);
    }

    return typeFromStringRelationship;
}

CoreTools::SimpleCSV::RelationshipItemImpl::StringFromTypeRelationship CoreTools::SimpleCSV::RelationshipItemImpl::GetStringFromTypeRelationship()
{
    const StringFromTypeRelationship stringFromTypeRelationship{ { RelationshipType::ExtendedProperties, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/extended-properties"s },
                                                                 { RelationshipType::CustomProperties, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/custom-properties"s },
                                                                 { RelationshipType::Workbook, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument"s },
                                                                 { RelationshipType::CoreProperties, "http://schemas.openxmlformats.org/package/2006/relationships/metadata/core-properties"s },
                                                                 { RelationshipType::Worksheet, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/worksheet"s },
                                                                 { RelationshipType::Styles, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/styles"s },
                                                                 { RelationshipType::SharedStrings, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/sharedStrings"s },
                                                                 { RelationshipType::CalculationChain, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/calcChain"s },
                                                                 { RelationshipType::VBAProject, "http://schemas.microsoft.com/office/2006/relationships/vbaProject"s },
                                                                 { RelationshipType::ExternalLink, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLink"s },
                                                                 { RelationshipType::Theme, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/theme"s },
                                                                 { RelationshipType::Chartsheet, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chartsheet"s },
                                                                 { RelationshipType::ChartStyle, "http://schemas.microsoft.com/office/2011/relationships/chartStyle"s },
                                                                 { RelationshipType::ChartColorStyle, "http://schemas.microsoft.com/office/2011/relationships/chartColorStyle"s },
                                                                 { RelationshipType::Drawing, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/drawing"s },
                                                                 { RelationshipType::Image, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/image"s },
                                                                 { RelationshipType::Chart, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/chart"s },
                                                                 { RelationshipType::ExternalLinkPath, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/externalLinkPath"s },
                                                                 { RelationshipType::PrinterSettings, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/printerSettings"s },
                                                                 { RelationshipType::VMLDrawing, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/vmlDrawing"s },
                                                                 { RelationshipType::ControlProperties, "http://schemas.openxmlformats.org/officeDocument/2006/relationships/ctrlProp"s } };

    return stringFromTypeRelationship;
}

CoreTools::SimpleCSV::RelationshipType CoreTools::SimpleCSV::RelationshipItemImpl::GetTypeFromString(const string& typeString)
{
    static const auto typeFromStringRelationship = GetTypeFromStringRelationship();

    const auto iter = typeFromStringRelationship.find(typeString);

    if (iter != typeFromStringRelationship.cend())
    {
        return iter->second;
    }

    return RelationshipType::Unknown;
}

string CoreTools::SimpleCSV::RelationshipItemImpl::GetStringFromType(RelationshipType type)
{
    static const auto stringFromTypeRelationship = GetStringFromTypeRelationship();

    const auto iter = stringFromTypeRelationship.find(type);

    if (iter != stringFromTypeRelationship.cend())
    {
        return iter->second;
    }

    return string{};
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
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document�ѱ��ͷš�"s));
    }

    return relationshipNode.attribute(TextParsing::g_Target.data()).value();
}

string CoreTools::SimpleCSV::RelationshipItemImpl::GetID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (document.expired())
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Internal, SYSTEM_TEXT("document�ѱ��ͷš�"s));
    }

    return relationshipNode.attribute(TextParsing::g_ID.data()).value();
}