// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/07/31 15:40)

#include "AssistTools/AssistToolsExport.h"

#include "CopyrightData.h"
#include "Detail/CopyrightDataImpl.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/AssistToolsClassInvariantMacro.h"  

using std::make_shared;

AssistTools::CopyrightData
	::CopyrightData(int endYear, const System::String& versions, const System::String& projectChineseName)
	:impl{ endYear,versions,projectChineseName }
{
	ASSIST_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(AssistTools, CopyrightData)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(AssistTools, CopyrightData, GetEndYear,int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(AssistTools, CopyrightData, GetVersions, const System::String)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(AssistTools, CopyrightData, GetProjectChineseName, const System::String) 
