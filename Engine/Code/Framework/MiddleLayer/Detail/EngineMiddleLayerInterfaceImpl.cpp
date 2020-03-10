// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.4 (2019/08/01 13:05)

#include "Framework/FrameworkExport.h"

#include "EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/FrameworkCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

Framework::EngineMiddleLayerInterfaceImpl
	::EngineMiddleLayerInterfaceImpl(int containerSize)	
	:m_Container(containerSize)
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, EngineMiddleLayerInterfaceImpl)

Framework::MiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterfaceImpl
	::GetMiddleLayerInterface(int index)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_0(0 <= index && index < static_cast<int>(m_Container.size()), "索引越界");

	return m_Container[index].GetSmartPointer();
}

Framework::ConstMiddleLayerInterfaceSmartPointer Framework::EngineMiddleLayerInterfaceImpl
	::GetConstMiddleLayerInterface(int index) const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;
	FRAMEWORK_ASSERTION_0(0 <= index && index < static_cast<int>(m_Container.size()), "索引越界");

	return m_Container[index].GetSmartPointer();
}

void Framework::EngineMiddleLayerInterfaceImpl
	::SetMiddleLayerInterface(int index, const MiddleLayerInterfaceSmartPointer& middleLayer)
{
	FRAMEWORK_CLASS_IS_VALID_9;
	FRAMEWORK_ASSERTION_0(0 <= index && index < static_cast<int>(m_Container.size()), "索引越界");

	m_Container[index].Reset(middleLayer);
}

