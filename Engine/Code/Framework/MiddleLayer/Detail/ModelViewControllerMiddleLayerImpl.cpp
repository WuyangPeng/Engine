// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "ModelViewControllerMiddleLayerImpl.h"
  
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
 
Framework::ModelViewControllerMiddleLayerImpl ::ModelViewControllerMiddleLayerImpl(MAYBE_UNUSED int count) noexcept
    : m_ModelMiddleLayer{}, m_ViewMiddleLayer{}, m_ControllerMiddleLayer{}
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ModelViewControllerMiddleLayerImpl)

void Framework::ModelViewControllerMiddleLayerImpl
	::SetModelMiddleLayer(const MiddleLayerSharedPtr& modelMiddleLayer) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ModelMiddleLayer = modelMiddleLayer;
}

void Framework::ModelViewControllerMiddleLayerImpl
	::SetViewMiddleLayer(const MiddleLayerSharedPtr& viewMiddleLayer) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ViewMiddleLayer = viewMiddleLayer;
}

void Framework::ModelViewControllerMiddleLayerImpl
	::SetControllerMiddleLayer(const MiddleLayerSharedPtr& controllerMiddleLayer) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	m_ControllerMiddleLayer = controllerMiddleLayer;
}

const Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetModelMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ModelMiddleLayer.lock();
}

const Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetViewMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ViewMiddleLayer.lock();
}

const Framework::ModelViewControllerMiddleLayerImpl::MiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetControllerMiddleLayer() noexcept
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return m_ControllerMiddleLayer.lock();
}

const Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetConstModelMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ModelMiddleLayer.lock();
}

const Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetConstViewMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ViewMiddleLayer.lock();
}

const Framework::ModelViewControllerMiddleLayerImpl::ConstMiddleLayerSharedPtr Framework::ModelViewControllerMiddleLayerImpl
	::GetConstControllerMiddleLayer() const noexcept
{
	FRAMEWORK_CLASS_IS_VALID_CONST_9;

	return m_ControllerMiddleLayer.lock();
}

