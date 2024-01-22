/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:00)

#include "CoreTools/CoreToolsExport.h"

#include "XmlData.h"
#include "Detail/XmlDataImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::SimpleCSV::XmlData::XmlData(const DocumentSharedPtr& parentDocument, const std::string& xmlPath, const std::string& xmlId, ContentType xmlType)
    : impl{ parentDocument, xmlPath, xmlId, xmlType }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlData)

void CoreTools::SimpleCSV::XmlData::SetRawData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetRawData(data);
}

std::string CoreTools::SimpleCSV::XmlData::GetRawData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRawData();
}

std::string CoreTools::SimpleCSV::XmlData::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlPath();
}

std::string CoreTools::SimpleCSV::XmlData::GetXmlId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlId();
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::XmlData::GetXmlType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlType();
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::SimpleCSV::XmlData::GetXmlDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetXmlDocument();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::XmlData::GetXmlDocument() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlDocument();
}

CoreTools::SimpleCSV::XmlData::DocumentWeakPtr CoreTools::SimpleCSV::XmlData::GetParentDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetParentDocument();
}
