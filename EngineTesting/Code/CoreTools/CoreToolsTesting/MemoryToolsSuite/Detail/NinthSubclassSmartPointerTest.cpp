// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 10:39)

#include "NinthSubclassSmartPointerTest.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;

CoreTools::NinthSubclassSmartPointerTest
	::NinthSubclassSmartPointerTest(int value, const string& name, double ratio)
	:ParentType{ value,name }, m_Ratio{ ratio }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NinthSubclassSmartPointerTest)

double CoreTools::NinthSubclassSmartPointerTest
	::GetRatio() const noexcept
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Ratio;
}
