// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:05)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayerImpl.h"
#include "CoreTools/MemoryTools/SubclassSmartPointerDetail.h"
#include "CoreTools/MemoryTools/SubclassWeakPointerDetail.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

Framework::ModelViewControllerMiddleLayerImpl
	::ModelViewControllerMiddleLayerImpl()
	:m_ModelMiddleLayer(),m_ViewMiddleLayer(), m_ControllerMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,ModelViewControllerMiddleLayerImpl)

void Framework::ModelViewControllerMiddleLayerImpl
    ::SetModelMiddleLayer( const MiddleLayerInterfaceSmartPointer& modelMiddleLayer )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ModelMiddleLayer.Reset(modelMiddleLayer);
}

void Framework::ModelViewControllerMiddleLayerImpl
	::SetViewMiddleLayer( const MiddleLayerInterfaceSmartPointer& viewMiddleLayer )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ViewMiddleLayer.Reset(viewMiddleLayer);
}

void Framework::ModelViewControllerMiddleLayerImpl
	::SetControllerMiddleLayer( const MiddleLayerInterfaceSmartPointer& controllerMiddleLayer )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ControllerMiddleLayer.Reset(controllerMiddleLayer);
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetModelMiddleLayer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ModelMiddleLayer.GetSmartPointer();
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetViewMiddleLayer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ViewMiddleLayer.GetSmartPointer();
}

const Framework::MiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetControllerMiddleLayer()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ControllerMiddleLayer.GetSmartPointer();
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetConstModelMiddleLayer() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ModelMiddleLayer.GetConstSmartPointer();
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetConstViewMiddleLayer() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ViewMiddleLayer.GetConstSmartPointer();
}

const Framework::ConstMiddleLayerInterfaceSmartPointer Framework::ModelViewControllerMiddleLayerImpl
	::GetConstControllerMiddleLayer() const
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ControllerMiddleLayer.GetConstSmartPointer();
}

 

