// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 17:14)

#include "CoreTools/CoreToolsExport.h"

#include "ParametersInterface.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

using std::make_shared;

 

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ParametersInterface)

const CoreTools::ParametersInterface::BaseSharedPtr CoreTools::ParametersInterface
	::Clone() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

