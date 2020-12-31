// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:51)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterfaceImpl.h"  
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

using std::const_pointer_cast;

Framework::EngineMiddleLayerInterfaceImpl
	::EngineMiddleLayerInterfaceImpl(int containerSize)
	:m_Container(containerSize)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineMiddleLayerInterfaceImpl)

Framework::MiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl
	::GetMiddleLayerInterface(int index)
{
	FRAMEWORK_CLASS_IS_VALID_9;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26473)   
	return const_pointer_cast<MiddleLayerInterface>(static_cast<const ClassType*>(this)->GetMiddleLayerInterface(index));
#include STSTEM_WARNING_POP	 
}

Framework::ConstMiddleLayerInterfaceSharedPtr Framework::EngineMiddleLayerInterfaceImpl
	::GetMiddleLayerInterface(int index) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_Container.at(index).lock();
}

void Framework::EngineMiddleLayerInterfaceImpl
	::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSharedPtr& middleLayer)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_Container.at(index) = middleLayer;
}

int Framework::EngineMiddleLayerInterfaceImpl
	::GetSize() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Container.size());
}

