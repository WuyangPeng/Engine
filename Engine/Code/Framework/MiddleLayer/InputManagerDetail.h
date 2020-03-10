// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 11:34)

#ifndef FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H
#define FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H

#include "InputManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename ApplicationTrait>
Framework::InputManager<ApplicationTrait>
	::InputManager()
	:ParentType{}
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

template <typename ApplicationTrait>
Framework::InputManager<ApplicationTrait>
	::~InputManager()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::IsValid() const noexcept
{
	if(ParentType::IsValid())
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::PreCreate())
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Initialize())
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
void Framework::InputManager<ApplicationTrait>
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::PreIdle();
}

template <typename ApplicationTrait>
void Framework::InputManager<ApplicationTrait>
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	ParentType::Terminate();
}

template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Move( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Move(point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Resize( WindowDisplayFlags type, const WindowSize& size )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Resize(type,size))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::KeyDown( uint8_t key,const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::KeyDown(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::KeyUp( uint8_t key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::KeyUp(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::SpecialKeyDown( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::SpecialKeyDown(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::SpecialKeyUp( int key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::SpecialKeyUp(key,point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::MouseClick( MouseButtonsTypes button,MouseStateTypes state, const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::MouseClick(button,state,point,virtualKeysTypes))
		return true;
	else
		return false;
}

template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Motion( const WindowPoint& point, const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Motion(point,virtualKeysTypes))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::PassiveMotion( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::PassiveMotion(point))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::MouseWheel( int delta,const WindowPoint& point,   const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::MouseWheel(delta,point,virtualKeysTypes))
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Create()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Create())
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Destroy())
		return true;
	else
		return false;
}


template <typename ApplicationTrait>
bool Framework::InputManager<ApplicationTrait>
	::Idle( int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_1;

	if(ParentType::Idle(timeDelta))
		return true;
	else
		return false;
}
 
#endif // FRAMEWORK_MIDDLE_LAYER_INPUT_MANAGER_DETAIL_H

