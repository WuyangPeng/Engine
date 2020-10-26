//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 11:19)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacingImpl.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::StringReplacingImpl::StringReplacingImpl(const string& configurationFileName)
    : m_Replacing{}
{
    InitReplacing(configurationFileName);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::StringReplacingImpl::InitReplacing(const string& configurationFileName)
{
    boost::property_tree::basic_ptree<System::String, System::String> mainTree;

    read_json(configurationFileName, mainTree);

    for (const auto& value : mainTree)
    {
        m_Replacing.insert({ value.first, value.second.get_value<System::String>() });
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacingImpl)

const System::String CoreTools::StringReplacingImpl::GetReplacing(const String& original) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = m_Replacing.find(original);

    if (iter != m_Replacing.cend())
        return iter->second;
    else
        return String{};
}
