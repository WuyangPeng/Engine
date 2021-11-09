///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/01 21:24)

#include "CoreTools/CoreToolsExport.h"

#include "XmlDataImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/SimpleCSV/Document.h"

#include <sstream>

using std::ostringstream;
using std::string;

CoreTools::SimpleCSV::XmlDataImpl::XmlDataImpl(const DocumentSharedPtr& parentDocument, const string& xmlPath, const string& xmlID, ContentType xmlType)
    : parentDocument{ parentDocument },
      xmlPath{ xmlPath },
      xmlID{ xmlID },
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
      xmlID{ std::move(rhs.xmlID) },
      xmlType{ std::move(rhs.xmlType) },
      xmlDocument{ std::move(rhs.xmlDocument) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::SimpleCSV::XmlDataImpl& CoreTools::SimpleCSV::XmlDataImpl::operator=(XmlDataImpl&& rhs) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    parentDocument = std::move(rhs.parentDocument);
    xmlPath = std::move(rhs.xmlPath);
    xmlID = std::move(rhs.xmlID);
    xmlType = std::move(rhs.xmlType);
    xmlDocument = std::move(rhs.xmlDocument);

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

void CoreTools::SimpleCSV::XmlDataImpl::SetRawData(const string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    xmlDocument->load_string(data.c_str(), loadFlags);
}

std::string CoreTools::SimpleCSV::XmlDataImpl::GetRawData() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    ostringstream os{};
    xmlDocument->save(os, "", pugi::format_raw);

    return os.str();
}

CoreTools::SimpleCSV::XmlDataImpl::DocumentWeakPtr CoreTools::SimpleCSV::XmlDataImpl::GetParentDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return parentDocument;
}

string CoreTools::SimpleCSV::XmlDataImpl::GetXmlPath() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlPath;
}

string CoreTools::SimpleCSV::XmlDataImpl::GetXmlID() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlID;
}

CoreTools::SimpleCSV::ContentType CoreTools::SimpleCSV::XmlDataImpl::GetXmlType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlType;
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::SimpleCSV::XmlDataImpl::GetXmlDocument() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)

    return std::const_pointer_cast<XMLDocument>(static_cast<const ClassType*>(this)->GetXmlDocument());

#include STSTEM_WARNING_POP
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::SimpleCSV::XmlDataImpl::GetXmlDocument() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return xmlDocument;
}
