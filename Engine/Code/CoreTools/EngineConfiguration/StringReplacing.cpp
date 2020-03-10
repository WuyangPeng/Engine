// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 16:16)

#include "CoreTools/CoreToolsExport.h"

#include "StringReplacing.h"
#include "Detail/StringReplacingImpl.h" 
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"  

using std::string;
using std::make_shared;

CoreTools::StringReplacing
	::StringReplacing(const string& configurationFileName)
	:m_Impl{ make_shared<ImplType>(configurationFileName) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StringReplacing)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(CoreTools, StringReplacing, GetReplacing, System::String, const System::String);
