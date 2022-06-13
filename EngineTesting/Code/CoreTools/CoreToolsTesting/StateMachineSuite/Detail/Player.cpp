///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/18 11:13)

#include "Player.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Player::Player() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Player)

void CoreTools::Player::StartPlayback(MAYBE_UNUSED const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::CloseDrawer(MAYBE_UNUSED const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::OpenDrawer(MAYBE_UNUSED const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::StoreCdInfo(MAYBE_UNUSED const CdDetected& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::PausePlayback(MAYBE_UNUSED const Pause& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::ResumePlayback(MAYBE_UNUSED const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::StopPlayback(MAYBE_UNUSED const Stop& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}

void CoreTools::Player::StopAndOpen(MAYBE_UNUSED const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;
}
