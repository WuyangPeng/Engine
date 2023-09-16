///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 15:09)

#include "CoreTools/CoreToolsExport.h"

#include "XmlDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"

#include <sstream>

CoreTools::SimpleCSV::XmlDataImpl::XmlDataImpl(const DocumentSharedPtr& parentDocument, const std::string& xmlPath, std::string xmlId, ContentType xmlType)
    : parentDocument{ parentDocument },
      xmlPath{ xmlPath },
      xmlId{ std::move(xmlId) },
      xmlType{ xmlType },
      xmlDocument{ std::make_shared<XMLDocument>() }
{
    xmlDocument->reset();
    if (!xmlDocument->document_element())
    {
        xmlDocument->load_string(parentDocument->ExtractXmlFromArchive(xmlPath).c_str(), loadFlags);
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::XmlDataImpl::XmlDataImpl(XmlDataImpl&& rhs) noexcept
    : parentDocument{ std::move(rhs.parentDocument) },
      xmlPath{ std::move(rhs.xmlPath) },
      xmlId{ std::move(rhs.xmlId) },
      xmlType{ rhs.xmlType },
      xmlDocument{ std::move(rhs.xmlDocument) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::XmlDataImpl& CoreTools::SimpleCSV::XmlDataImpl::operator=(XmlDataImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (this != &rhs)
    {
        parentDocument = std::move(rhs.parentDocument);
        xmlPath = std::move(rhs.xmlPath);
        xmlId = std::move(rhs.xmlId);
        xmlType = rhs.xmlType;
        xmlDocument = std::move(rhs.xmlDocument);
    }

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::SimpleCSV::XmlDataImpl::IsValid() const noexcept
{
    if (xmlDocument != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::SimpleCSV::XmlDataImpl::SetRawData(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    xmlDocument->load_string(data.c_str(), loadFlags);
}

std::string CoreTools::SimpleCSV::XmlDataImpl::GetRawData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    std::ostringstream os{};
    xmlDocument->save(os, "", pugi::format_raw);

    return os.str();
}

CoreTools::SimpleCSV::XmlDataImpl::DocumentWeakPtr CoreTools::SimpleCSV::XmlDataImpl::GetParentDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return parentDocument;
}

std::string CoreTools::SimpleCSV::XmlDataImpl::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlPath;
}

std::string CoreTools::SimpleCSV::XmlDataImpl::GetXmlId() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlId;
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::XmlDataImpl::GetXmlType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlType;
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::SimpleCSV::XmlDataImpl::GetXmlDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<XMLDocument>(static_cast<const ClassType*>(this)->GetXmlDocument());

#include SYSTEM_WARNING_POP
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::XmlDataImpl::GetXmlDocument() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlDocument;
}
