///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 16:28)

#include "XmlFileTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::XmlFileTest::XmlFileTest(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, XmlFileTest)

string CoreTools::XmlFileTest::GetXmlDataByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetXmlData();
}

void CoreTools::XmlFileTest::SetXmlDataByXmlFile(const string& data)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    SetXmlData(data);
}

string CoreTools::XmlFileTest::GetRelationshipIDByXmlFile() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return GetRelationshipID();
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
