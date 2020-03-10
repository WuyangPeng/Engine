// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:34)

#ifndef FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_DETAIL_H

#include "ModelMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h" 

template <typename SmartPointer,typename Subclass, typename Function>
const SmartPointer Framework::MiddleLayerInterface
	::GetSmartPointer(Subclass* subClass, Function function)
{
	static_assert(std::is_same<SmartPointer::IsNonConstType, CoreTools::TrueType>::value);
	static_assert(std::is_member_function_pointer<Function>::value);
	static_assert(std::is_base_of<ClassType, Subclass>::value);

	FRAMEWORK_CLASS_IS_VALID_9;

	MiddleLayerInterfaceSmartPointer middleLayer = (subClass->*function)();

	return middleLayer.PolymorphicDowncastSmartPointer<SmartPointer>();
}

template <typename ConstSmartPointer,typename Subclass, typename Function>
const ConstSmartPointer Framework::MiddleLayerInterface
	::GetConstSmartPointer(Subclass* subClass, Function function) const
{
	static_assert(std::is_same<ConstSmartPointer::IsConstType, CoreTools::TrueType>::value);
	static_assert(std::is_member_function_pointer<Function>::value);
	static_assert(std::is_base_of<ClassType, Subclass>::value);

	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	ConstMiddleLayerInterfaceSmartPointer middleLayer = (subClass->*function)();

	return	middleLayer.PolymorphicDowncastConstSmartPointer<ConstSmartPointer>();
}
  
#endif // FRAMEWORK_MIDDLE_LAYER_MIDDLE_LAYER_INTERFACE_DETAIL_H

