// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:08)

#include "Framework/FrameworkExport.h"

#include "MiddleLayerInterface.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "System/Helper/UnusedMacro.h"

Framework::MiddleLayerInterface
	::MiddleLayerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

Framework::MiddleLayerInterface
	::~MiddleLayerInterface()
{
	FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework,MiddleLayerInterface)

bool Framework::MiddleLayerInterface
    ::Create()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::MiddleLayerInterface
	::Move( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::Resize(WindowDisplayFlags type,const WindowSize& size)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(type);
	SYSTEM_UNUSED_ARG(size);

	return true;
}

bool Framework::MiddleLayerInterface
	::Paint()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::MiddleLayerInterface
	::KeyDown( uint8_t key, const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::KeyUp( uint8_t key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::SpecialKeyDown( int key, const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::SpecialKeyUp( int key,const WindowPoint& point)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(key);
	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::MouseClick( MouseButtonsTypes button,MouseStateTypes state,
			      const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes)
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(button);
	SYSTEM_UNUSED_ARG(state);
	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeysTypes);

	return true;
}

bool Framework::MiddleLayerInterface
	::Motion( const WindowPoint& point,const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeysTypes);

	return true;
}

bool Framework::MiddleLayerInterface
	::PassiveMotion( const WindowPoint& point )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(point);

	return true;
}

bool Framework::MiddleLayerInterface
	::MouseWheel( int delta,const WindowPoint& point,
	              const VirtualKeysTypes& virtualKeysTypes )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(delta);
	SYSTEM_UNUSED_ARG(point);
	SYSTEM_UNUSED_ARG(virtualKeysTypes);

	return true;
}

bool Framework::MiddleLayerInterface
	::Destroy()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::MiddleLayerInterface
	::Idle( int64_t timeDelta )
{
	FRAMEWORK_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(timeDelta);

	return true;
}

bool Framework::MiddleLayerInterface
	::PreCreate()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

bool Framework::MiddleLayerInterface
	::Initialize()
{
	FRAMEWORK_CLASS_IS_VALID_9;

	return true;
}

void Framework::MiddleLayerInterface
	::PreIdle()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

void Framework::MiddleLayerInterface
	::Terminate()
{
	FRAMEWORK_CLASS_IS_VALID_9;
}

