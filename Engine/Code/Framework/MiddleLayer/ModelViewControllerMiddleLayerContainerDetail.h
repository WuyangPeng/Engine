// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:44)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "ModelViewControllerMiddleLayerContainer.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::ModelViewControllerMiddleLayerContainer(MiddleLayerPlatform middleLayerPlatform)
	:ParentType{ middleLayerPlatform },
	 m_ModelMiddleLayer{ std::make_shared<ModelMiddleLayerType>(middleLayerPlatform) },
	 m_ViewMiddleLayer{ std::make_shared<ViewMiddleLayerType>(middleLayerPlatform) },
	 m_ControllerMiddleLayer{ std::make_shared<ControllerMiddleLayerType>(middleLayerPlatform) }
{
	m_ModelMiddleLayer->SetViewMiddleLayer(m_ViewMiddleLayer);
	m_ModelMiddleLayer->SetControllerMiddleLayer(m_ControllerMiddleLayer);

	m_ViewMiddleLayer->SetModelMiddleLayer(m_ModelMiddleLayer);
	m_ViewMiddleLayer->SetControllerMiddleLayer(m_ControllerMiddleLayer);

	m_ControllerMiddleLayer->SetModelMiddleLayer(m_ModelMiddleLayer);
	m_ControllerMiddleLayer->SetViewMiddleLayer(m_ViewMiddleLayer);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::ModelViewControllerMiddleLayerContainer(ModelViewControllerMiddleLayerContainer&& rhs) noexcept
	:ParentType{ std::move(rhs) },
	 m_ModelMiddleLayer{ std::move(rhs.m_ModelMiddleLayer) },
	 m_ViewMiddleLayer{ std::move(rhs.m_ViewMiddleLayer) },
	 m_ControllerMiddleLayer{ std::move(rhs.m_ControllerMiddleLayer) }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>& Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::operator=(ModelViewControllerMiddleLayerContainer&& rhs) noexcept
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::operator=(std::move(rhs));

	m_ModelMiddleLayer = std::move(rhs.m_ModelMiddleLayer);
	m_ViewMiddleLayer = std::move(rhs.m_ViewMiddleLayer);
	m_ControllerMiddleLayer = std::move(rhs.m_ControllerMiddleLayer);

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_ModelMiddleLayer && m_ViewMiddleLayer && m_ControllerMiddleLayer)
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::PreCreate(const EnvironmentDirectory& environmentDirectory)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PreCreate(environmentDirectory) && m_ModelMiddleLayer->PreCreate(environmentDirectory) && m_ViewMiddleLayer->PreCreate(environmentDirectory) && m_ControllerMiddleLayer->PreCreate(environmentDirectory))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Create()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Create() && m_ModelMiddleLayer->Create() && m_ViewMiddleLayer->Create() && m_ControllerMiddleLayer->Create())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Initialize()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Initialize() && m_ModelMiddleLayer->Initialize() && m_ViewMiddleLayer->Initialize() && m_ControllerMiddleLayer->Initialize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Destroy()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Destroy() && m_ModelMiddleLayer->Destroy() && m_ViewMiddleLayer->Destroy() && m_ControllerMiddleLayer->Destroy())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Terminate()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::Terminate();

	m_ModelMiddleLayer->Terminate();
	m_ViewMiddleLayer->Terminate();
	m_ControllerMiddleLayer->Terminate();
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::PreIdle()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	ParentType::PreIdle();

	m_ModelMiddleLayer->PreIdle();
	m_ViewMiddleLayer->PreIdle();
	m_ControllerMiddleLayer->PreIdle();
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Idle(int64_t timeDelta)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Idle(timeDelta) && m_ModelMiddleLayer->Idle(timeDelta) && m_ViewMiddleLayer->Idle(timeDelta) && m_ControllerMiddleLayer->Idle(timeDelta))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Paint()
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Paint() && m_ViewMiddleLayer->Paint())
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Move(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Move(point) && m_ViewMiddleLayer->Move(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Resize(windowDisplay, size) && m_ViewMiddleLayer->Resize(windowDisplay, size))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::KeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::KeyUp(key, point) && m_ControllerMiddleLayer->KeyUp(key, point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::KeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::KeyDown(key, point) && m_ControllerMiddleLayer->KeyDown(key, point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::SpecialKeyUp(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::SpecialKeyUp(key, point) && m_ControllerMiddleLayer->SpecialKeyUp(key, point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::SpecialKeyDown(int key, const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::SpecialKeyDown(key, point) && m_ControllerMiddleLayer->SpecialKeyDown(key, point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::PassiveMotion(const WindowPoint& point)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::PassiveMotion(point) && m_ControllerMiddleLayer->PassiveMotion(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::Motion(point, virtualKeys) && m_ControllerMiddleLayer->Motion(point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::MouseWheel(delta, point, virtualKeys) && m_ControllerMiddleLayer->MouseWheel(delta, point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait, typename ModelMiddleLayer, typename ViewMiddleLayer, template<typename> class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait, ModelMiddleLayer, ViewMiddleLayer, ControllerMiddleLayer>
	::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	if (ParentType::MouseClick(button, state, point, virtualKeys) && m_ControllerMiddleLayer->MouseClick(button, state, point, virtualKeys))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H

