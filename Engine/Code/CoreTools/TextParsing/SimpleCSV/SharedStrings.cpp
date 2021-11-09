///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.4 (2021/10/04 21:13)

#include "CoreTools/CoreToolsExport.h"

#include "Document.h"
#include "SharedStrings.h"
#include "Detail/SharedStringsImpl.h"
#include "System/Helper/PragmaWarning/PugiXml.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/TextParsing/Flags/CSVConstant.h"

using std::string;

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

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, SharedStrings, GetStringIndex, string, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools::SimpleCSV, SharedStrings, IsStringExists, string, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, SharedStrings, IsStringExists, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(CoreTools::SimpleCSV, SharedStrings, GetString, int, const string&)

int CoreTools::SimpleCSV::SharedStrings::AppendString(const string& str)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    auto textNode = GetXmlDocument()->document_element().append_child("si").append_child("t");
    if (str.front() == TextParsing::g_Space || str.back() == TextParsing::g_Space)
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
    auto iter = children.begin();
    if (!children.empty() && index < std::distance(iter, children.end()))
    {
        std::advance(iter, index);
        iter->text().set("");
        impl->ClearString(index);
    }
    else
    {
        THROW_SIMPLE_CSV_EXCEPTION(CSVExceptionType::Input, SYSTEM_TEXT("索引越界！"s));
    }
}
