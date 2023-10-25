///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 10:58)

#include "XmlFileTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::XmlFileTest::XmlFileTest(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, XmlFileTest)

std::string CoreTools::XmlFileTest::GetXmlDataByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlData();
}

void CoreTools::XmlFileTest::SetXmlDataByXmlFile(const std::string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetXmlData(data);
}

std::string CoreTools::XmlFileTest::GetRelationshipIdByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRelationshipId();
}

CoreTools::XmlFileTest::DocumentSharedPtr CoreTools::XmlFileTest::GetParentDocumentByXmlFile()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetParentDocument();
}

CoreTools::XmlFileTest::ConstDocumentSharedPtr CoreTools::XmlFileTest::GetParentDocumentByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetParentDocument();
}

CoreTools::SimpleCSV::XMLDocumentSharedPtr CoreTools::XmlFileTest::GetXmlDocumentByXmlFile()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return GetXmlDocument();
}

CoreTools::SimpleCSV::ConstXMLDocumentSharedPtr CoreTools::XmlFileTest::GetXmlDocumentByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlDocument();
}
