// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.4 (2019/09/10 19:40)

#include "EngineMiddleLayerMessage.h"
#include "Testing.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/InputManagerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"

EngineMiddleLayer::EngineMiddleLayerMessage::EngineMiddleLayerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::ConsoleAlloc::Create() }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(EngineMiddleLayer, EngineMiddleLayerMessage)
