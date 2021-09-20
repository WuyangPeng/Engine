// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:40)

#include "SixthSubclassSmartPointerTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::SixthSubclassSmartPointerTest
	::SixthSubclassSmartPointerTest(int value, const string& name)
	:ParentType{ value,name }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SixthSubclassSmartPointerTest)
