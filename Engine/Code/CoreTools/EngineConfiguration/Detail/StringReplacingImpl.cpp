/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 14:52)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacingImpl.h"
#include "System/Helper/PragmaWarning/PropertyTree.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::StringReplacingImpl::StringReplacingImpl(const std::string& configurationFileName)
    : replacing{}
{
    InitReplacing(configurationFileName);

    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::StringReplacingImpl::InitReplacing(const std::string& configurationFileName)
{
    boost::property_tree::basic_ptree<System::String, System::String> mainTree;

    read_json(configurationFileName, mainTree);

    for (const auto& [key, value] : mainTree)
    {
        replacing.emplace(key, value.get_value<System::String>());
    }
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacingImpl)

System::String CoreTools::StringReplacingImpl::GetReplacing(const String& original) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    if (const auto iter = replacing.find(original); iter != replacing.cend())
        return iter->second;
    else
        return String{};
}
