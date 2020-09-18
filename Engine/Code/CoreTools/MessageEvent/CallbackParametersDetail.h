// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:06)

#ifndef CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H 

#include "CallbackParameters.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 


template<typename ConstSubclass>
std::shared_ptr<const ConstSubclass> CoreTools::CallbackParameters
	::GetParametersInterfacePolymorphicDowncast(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return PolymorphicSharedPtrDowncast<ConstSubclass>(GetParametersInterfaceValue(index));
}

template<typename ConstSubclass>
std::shared_ptr<const ConstSubclass> CoreTools::CallbackParameters
	::GetParametersInterfacePolymorphicCast(int index) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return PolymorphicSharedPtrCast<ConstSubclass>(GetParametersInterfaceValue(index));
}

#endif // CORE_TOOLS_MESSAGE_EVENT_CALLBACK_PARAMETERS_DETAIL_H
