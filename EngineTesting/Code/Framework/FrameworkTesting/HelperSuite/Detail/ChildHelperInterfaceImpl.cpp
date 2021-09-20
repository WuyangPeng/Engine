// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.3.0.1 (2020/05/27 14:14)

#include "ChildHelperInterfaceImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::const_pointer_cast;

Framework::ChildHelperInterfaceImpl
	::ChildHelperInterfaceImpl(int containerSize)
	:m_Container(containerSize)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ChildHelperInterfaceImpl)

Framework::MiddleLayerInterfaceSharedPtr Framework::ChildHelperInterfaceImpl
	::GetMiddleLayerInterface(int index)
{
	FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)   
	return const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType*>(this)->GetMiddleLayerInterface(index));
#include STSTEM_WARNING_POP	 
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::ChildHelperInterfaceImpl
	::GetMiddleLayerInterface(int index) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Container.at(index).lock();
}

void Framework::ChildHelperInterfaceImpl
	::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_Container.at(index) = middleLayer;
}

int Framework::ChildHelperInterfaceImpl
	::GetSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Container.size());
}

