// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:10)

#include "CoreTools/CoreToolsExport.h"

#include "CallbackParametersImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

CoreTools::CallbackParametersImpl
	::CallbackParametersImpl(int count)
	:m_Container(count)
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, CallbackParametersImpl)

int CoreTools::CallbackParametersImpl
	::GetContainerSize() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Container.size());
}

