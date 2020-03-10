// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:34)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H

#include "ModelViewControllerMiddleLayerContainer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemoryMacro.h"

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::ModelViewControllerMiddleLayerContainer()
	:ParentType{},m_ModelMiddleLayer(NEW0 ModelMiddleLayerType),
	 m_ViewMiddleLayer(NEW0 ViewMiddleLayerType),
	 m_ControllerMiddleLayer(NEW0 ControllerMiddleLayerType)
{	
	m_ModelMiddleLayer->SetViewMiddleLayer(m_ViewMiddleLayer);
	m_ModelMiddleLayer->SetControllerMiddleLayer(m_ControllerMiddleLayer);

	m_ViewMiddleLayer->SetModelMiddleLayer(m_ModelMiddleLayer);
	m_ViewMiddleLayer->SetControllerMiddleLayer(m_ControllerMiddleLayer);

	m_ControllerMiddleLayer->SetModelMiddleLayer(m_ModelMiddleLayer);
	m_ControllerMiddleLayer->SetViewMiddleLayer(m_ViewMiddleLayer);

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::~ModelViewControllerMiddleLayerContainer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::IsValid() const noexcept
{
	if(ParentType::IsValid() && m_ModelMiddleLayer.IsValidPtr() &&
	   m_ViewMiddleLayer.IsValidPtr() && m_ControllerMiddleLayer.IsValidPtr())
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::PreCreate() && m_ModelMiddleLayer->PreCreate() &&
	   m_ViewMiddleLayer->PreCreate() && m_ControllerMiddleLayer->PreCreate())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Initialize() && m_ModelMiddleLayer->Initialize() &&
	   m_ViewMiddleLayer->Initialize() && m_ControllerMiddleLayer->Initialize())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::PreIdle();
	
	m_ModelMiddleLayer->PreIdle();	
	m_ViewMiddleLayer->PreIdle();
	m_ControllerMiddleLayer->PreIdle();
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
void Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::Terminate();

	m_ModelMiddleLayer->Terminate();	
	m_ViewMiddleLayer->Terminate();
	m_ControllerMiddleLayer->Terminate();
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Paint()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Paint() && m_ViewMiddleLayer->Paint())
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Move( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Move(point) && m_ControllerMiddleLayer->Move(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Resize(type,size) && m_ControllerMiddleLayer->Resize(type,size))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::KeyDown( uint8_t key,const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::KeyDown(key,point) && m_ControllerMiddleLayer->KeyDown(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::KeyUp( uint8_t key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::KeyUp(key,point) && m_ControllerMiddleLayer->KeyUp(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::SpecialKeyDown( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::SpecialKeyDown(key,point) && m_ControllerMiddleLayer->SpecialKeyDown(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::SpecialKeyUp( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::SpecialKeyUp(key,point) && m_ControllerMiddleLayer->SpecialKeyUp(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::MouseClick( MouseButtonsTypes button,MouseStateTypes state,const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::MouseClick(button,state,point,virtualKeysTypes) &&
	   m_ControllerMiddleLayer->MouseClick(button,state,point,virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Motion( const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Motion(point,virtualKeysTypes) &&
	   m_ControllerMiddleLayer->Motion(point,virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::PassiveMotion( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::PassiveMotion(point) && m_ControllerMiddleLayer->PassiveMotion(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::MouseWheel( int delta,const WindowPoint& point, 
	              const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::MouseWheel(delta,point,virtualKeysTypes) &&
	   m_ControllerMiddleLayer->MouseWheel(delta,point,virtualKeysTypes))
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Create()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Create() && m_ModelMiddleLayer->Create() &&
       m_ViewMiddleLayer->Create() && m_ControllerMiddleLayer->Create())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Destroy() && m_ModelMiddleLayer->Destroy() &&
	   m_ViewMiddleLayer->Destroy() && m_ControllerMiddleLayer->Destroy())
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait,typename ModelMiddleLayer,typename ViewMiddleLayer,
		  template<typename > class ControllerMiddleLayer>
bool Framework::ModelViewControllerMiddleLayerContainer<ApplicationTrait,ModelMiddleLayer,ViewMiddleLayer,ControllerMiddleLayer>
	::Idle( int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if (ParentType::Idle(timeDelta) && m_ModelMiddleLayer->Idle(timeDelta) &&
		m_ViewMiddleLayer->Idle(timeDelta) && m_ControllerMiddleLayer->Idle(timeDelta))
	{
		return true;
	}
	else
	{
		return false;
	}
}

#endif // FRAMEWORK_MIDDLE_LAYER_MODEL_VIEW_CONTROLLER_MIDDLE_LAYER_CONTAINER_DETAIL_H

