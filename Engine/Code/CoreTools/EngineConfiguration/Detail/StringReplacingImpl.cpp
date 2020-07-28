// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:16)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacingImpl.h" 
#include "System/Helper/PragmaWarning/PropertyTree.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"  

using std::string;

CoreTools::StringReplacingImpl
	::StringReplacingImpl(const string& configurationFileName)
	:m_Replacing{}
{
	InitReplacing(configurationFileName);

	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

void CoreTools::StringReplacingImpl
	::InitReplacing(const string& configurationFileName)
{
	boost::property_tree::basic_ptree<System::String, System::String> mainTree;

	read_json(configurationFileName, mainTree);

	for (const auto& value : mainTree)
	{
		m_Replacing.insert({ value.first, value.second.get_value<System::String>() });
	}
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacingImpl)

const System::String CoreTools::StringReplacingImpl
	::GetReplacing(const System::String& original) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	const auto iter = m_Replacing.find(original);

	if (iter != m_Replacing.cend())
		return iter->second;
	else
		return SYSTEM_TEXT("");
}


