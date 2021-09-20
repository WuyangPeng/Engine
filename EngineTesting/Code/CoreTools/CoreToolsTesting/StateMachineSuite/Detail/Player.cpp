// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:16)

#include "Player.h"

#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Player ::Player() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Player)

void CoreTools::Player ::StartPlayback([[maybe_unused]] const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::CloseDrawer([[maybe_unused]] const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::OpenDrawer([[maybe_unused]] const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::StoreCdInfo([[maybe_unused]] const CdDetected& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::PausePlayback([[maybe_unused]] const Pause& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::ResumePlayback([[maybe_unused]] const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::StopPlayback([[maybe_unused]] const Stop& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player ::StopAndOpen([[maybe_unused]] const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}
