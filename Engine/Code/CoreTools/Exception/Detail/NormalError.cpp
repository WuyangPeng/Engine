// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:47)

#include "CoreTools/CoreToolsExport.h"

#include "NormalError.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::NormalError
	::NormalError(const FunctionDescribed& functionDescribed, const String& message)
	:ParentType{ functionDescribed,message }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NormalError)


