///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/23 15:01)

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

    for (const auto& value : mainTree)
    {
        replacing.insert({ value.first, value.second.get_value<System::String>() });
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
