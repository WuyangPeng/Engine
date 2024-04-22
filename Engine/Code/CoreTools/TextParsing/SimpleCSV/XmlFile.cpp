/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:29)

#include "CoreTools/CoreToolsExport.h"

#include "XmlFile.h"
#include "Detail/XmlFileImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, XmlFile)

CoreTools::SimpleCSV::XmlFile::XmlFile(const XmlDataSharedPtr& xmlData)
    : impl{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools::SimpleCSV, XmlFile)

std::string CoreTools::SimpleCSV::XmlFile::GetXmlData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlData();
}

void CoreTools::SimpleCSV::XmlFile::SetXmlData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->SetXmlData(data);
}

std::string CoreTools::SimpleCSV::XmlFile::GetRelationshipId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetRelationshipId();
}

CoreTools::SimpleCSV::XmlFile::DocumentSharedPtr CoreTools::SimpleCSV::XmlFile::GetParentDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetParentDocument();
}

CoreTools::SimpleCSV::XmlFile::ConstDocumentSharedPtr CoreTools::SimpleCSV::XmlFile::GetParentDocument() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetParentDocument();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::XmlFile::GetXmlDocument() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetXmlDocument();
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::SimpleCSV::XmlFile::GetXmlDocument()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return impl->GetXmlDocument();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFile::GetSheetData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetSheetData();
}

CoreTools::SimpleCSV::XMLNode CoreTools::SimpleCSV::XmlFile::GetFirstChildColumns() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetFirstChildColumns();
}
