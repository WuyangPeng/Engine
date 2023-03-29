///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/08 11:42)

#include "CoreTools/CoreToolsExport.h"

#include "Properties.h"
#include "Detail/Utilities.h"
#include "System/Helper/PragmaWarning/PugiXml.h"

CoreTools::SimpleCSV::Properties::Properties(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Properties)

void CoreTools::SimpleCSV::Properties::SetProperty(const std::string& name, const std::string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    XMLNode node{};
    if (xmlDocument->first_child().child(name.c_str()) != nullptr)
    {
        node = xmlDocument->first_child().child(name.c_str());
    }
    else
    {
        node = xmlDocument->first_child().prepend_child(name.c_str());
    }

    node.text().set(value.c_str());
}

std::string CoreTools::SimpleCSV::Properties::GetProperty(const std::string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto xmlDocument = GetXmlDocument();

    auto property = xmlDocument->first_child().child(name.c_str());
    if (!property)
    {
        property = xmlDocument->first_child().append_child(name.c_str());
    }

    return property.text().get();
}

void CoreTools::SimpleCSV::Properties::DeleteProperty(const std::string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto xmlDocument = GetXmlDocument();

    if (const auto property = xmlDocument->first_child().child(name.c_str()); property != nullptr)
    {
        xmlDocument->first_child().remove_child(property);
    }
}
