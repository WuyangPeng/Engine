///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/09 12:35)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacingImpl.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::StringReplacingImpl::StringReplacingImpl(const string& configurationFileName)
    : replacing{}
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
        replacing.insert({ value.first, value.second.get_value<System::String>() });
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacingImpl)

const System::String CoreTools::StringReplacingImpl::GetReplacing(const String& original) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto iter = replacing.find(original);

    if (iter != replacing.cend())
        return iter->second;
    else
        return String{};
}
