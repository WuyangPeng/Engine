///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/20 22:27)

#include "CoreTools/CoreToolsExport.h"

#include "Properties.h"
#include "Detail/Utilities.h"
#include "System/Helper/PragmaWarning/PugiXml.h"

using std::string;

CoreTools::SimpleCSV::Properties::Properties(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, Properties)

void CoreTools::SimpleCSV::Properties::SetProperty(const string& name, const string& value)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

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

string CoreTools::SimpleCSV::Properties::GetProperty(const string& name) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    auto xmlDocument = GetXmlDocument();

    auto property = xmlDocument->first_child().child(name.c_str());
    if (!property)
    {
        property = xmlDocument->first_child().append_child(name.c_str());
    }

    return property.text().get();
}

void CoreTools::SimpleCSV::Properties::DeleteProperty(const string& name)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto xmlDocument = GetXmlDocument();

    const auto property = xmlDocument->first_child().child(name.c_str());
    if (property != nullptr)
    {
        xmlDocument->first_child().remove_child(property);
    }
}
