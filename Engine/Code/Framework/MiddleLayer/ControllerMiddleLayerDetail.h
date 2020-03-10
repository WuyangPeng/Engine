// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:29)

#ifndef FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H

#include "ControllerMiddleLayer.h" 
#include "ModelMiddleLayer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait>
Framework::ControllerMiddleLayer<ApplicationTrait>
	::ControllerMiddleLayer()
	:ParentType{}
{	
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

template <typename ApplicationTrait>
Framework::ControllerMiddleLayer<ApplicationTrait>
	::~ControllerMiddleLayer()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::PreCreate())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Initialize())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
void Framework::ControllerMiddleLayer<ApplicationTrait>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	ParentType::PreIdle();
}

template <typename ApplicationTrait>
void Framework::ControllerMiddleLayer<ApplicationTrait>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	ParentType::Terminate();
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Move(const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Move(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Resize(type,size))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::KeyDown( uint8_t key,const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::KeyDown(key,point))
	{
		if (key == ApplicationTrait::KeyIdentifiers::sm_KeyF5)
		{
			ModelMiddleLayerSmartPointer modelMiddleLayer = GetSmartPointer<ModelMiddleLayerSmartPointer>(this, &ClassType::GetModelMiddleLayer);

			if (modelMiddleLayer.IsValidPtr())
			{
				modelMiddleLayer->ResetTime();
			}
		}

		return true;
	}
	else
	{
		return false;
	}
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::KeyUp( uint8_t key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::KeyUp(key,point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyDown( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::SpecialKeyDown(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::SpecialKeyUp( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::SpecialKeyUp(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::MouseClick( MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::MouseClick(button,state,point,virtualKeysTypes))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Motion( const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Motion(point,virtualKeysTypes))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::PassiveMotion( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::PassiveMotion(point))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::MouseWheel( int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (ParentType::MouseWheel(delta, point, virtualKeysTypes))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Create()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Create())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if(ParentType::Destroy())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::ControllerMiddleLayer<ApplicationTrait>
	::Idle(int64_t timeDelta)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	if (ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}
 
#endif // FRAMEWORK_MIDDLE_LAYER_CONTROLLER_MIDDLE_LAYER_DETAIL_H