/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 11:28)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "SharedStrings.h"
#include "Detail/SharedStringsImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/TextParsingConstant.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(CoreTools::SimpleCSV, SharedStrings)

CoreTools::SimpleCSV::SharedStrings::SharedStrings(const XmlDataSharedPtr& xmlData)
    : ParentType{ xmlData }, impl{ ImplCreateUseDefaultConstruction::Default }
{
    for (const auto& str : GetXmlDocument()->document_element().children())
    {
        impl->AppendString(str.first_child().text().get());
    }

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools::SimpleCSV, SharedStrings)

int CoreTools::SimpleCSV::SharedStrings::GetStringIndex(const std::string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetStringIndex(str);
}

bool CoreTools::SimpleCSV::SharedStrings::IsStringExists(const std::string& str) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsStringExists(str);
}

bool CoreTools::SimpleCSV::SharedStrings::IsStringExists(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->IsStringExists(index);
}

const std::string& CoreTools::SimpleCSV::SharedStrings::GetString(int index) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return impl->GetString(index);
}

int CoreTools::SimpleCSV::SharedStrings::AppendString(const std::string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto textNode = GetXmlDocument()->document_element().append_child("si").append_child("t");
    if (str.front() == TextParsing::gSpace || str.back() == TextParsing::gSpace)
    {
        textNode.append_attribute("xml:space").set_value("preserve");
    }

    auto xmlText = textNode.text();

    xmlText.set(str.c_str());

    return impl->AppendString(xmlText.get());
}

void CoreTools::SimpleCSV::SharedStrings::ClearString(int index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    const auto children = GetXmlDocument()->document_element().children();

    if (auto iter = children.begin();
        !children.empty() && index < std::distance(iter, children.end()))
    {
        std::advance(iter, index);
        iter->text().set("");
        impl->ClearString(index);
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("索引越界！"s))
    }
}
