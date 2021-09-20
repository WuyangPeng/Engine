// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 14:53)

#include "Framework/FrameworkExport.h"

#include "AudioManagerInterface.h"
#include "Flags/AudioMiddleLayerFlags.h"
#include "Detail/EngineMiddleLayerInterfaceImpl.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::make_shared;

Framework::AudioManagerInterface ::AudioManagerInterface(MiddleLayerPlatform middleLayerPlatform)
    : ParentType{ middleLayerPlatform }, impl{ System::EnumCastUnderlying(AudioMiddleLayer::Count) }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AudioManagerInterface)

ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Audio, System)
ENGINE_MIDDLE_LAYER_MANAGER_DEFINE(Framework, Audio, Resource)

bool Framework::AudioManagerInterface ::Paint()
{
    ;

    return ParentType::Paint();
}

bool Framework::AudioManagerInterface ::Move(const WindowPoint& point)
{
    ;

    return ParentType::Move(point);
}

bool Framework::AudioManagerInterface ::Resize(WindowDisplay windowDisplay, const WindowSize& size)
{
    ;

    return ParentType::Resize(windowDisplay, size);
}

bool Framework::AudioManagerInterface ::KeyUp(int key, const WindowPoint& point)
{
    ;

    return ParentType::KeyUp(key, point);
}

bool Framework::AudioManagerInterface ::KeyDown(int key, const WindowPoint& point)
{
    ;

    return ParentType::KeyDown(key, point);
}

bool Framework::AudioManagerInterface ::SpecialKeyUp(int key, const WindowPoint& point)
{
    ;

    return ParentType::SpecialKeyUp(key, point);
}

bool Framework::AudioManagerInterface ::SpecialKeyDown(int key, const WindowPoint& point)
{
    ;

    return ParentType::SpecialKeyDown(key, point);
}

bool Framework::AudioManagerInterface ::PassiveMotion(const WindowPoint& point)
{
    ;

    return ParentType::PassiveMotion(point);
}

bool Framework::AudioManagerInterface ::Motion(const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::Motion(point, virtualKeys);
}

bool Framework::AudioManagerInterface ::MouseWheel(int delta, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::MouseWheel(delta, point, virtualKeys);
}

bool Framework::AudioManagerInterface ::MouseClick(MouseButtonsTypes button, MouseStateTypes state, const WindowPoint& point, const VirtualKeysTypes& virtualKeys)
{
    ;

    return ParentType::MouseClick(button, state, point, virtualKeys);
}
