// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:42)

#include "StaticPropertyExternal.h"  
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

string CoreTools::StaticPropertyExternal
	::sm_Value;

CoreTools::StaticPropertyExternal ::StaticPropertyExternal() noexcept
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, StaticPropertyExternal)

const string& CoreTools::StaticPropertyExternal ::GetValue() noexcept
{
	return sm_Value;
}

void CoreTools::StaticPropertyExternal
	::SetValue(const string& value)
{
	sm_Value = value;
}

