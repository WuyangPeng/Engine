///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/25 10:54)

#include "Player.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::Player::Player() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, Player)

void CoreTools::Player::StartPlayback(const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::CloseDrawer(const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::OpenDrawer(const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::StoreCdInfo(const CdDetected& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::PausePlayback(const Pause& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::ResumePlayback(const Play& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::StopPlayback(const Stop& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}

void CoreTools::Player::StopAndOpen(const OpenClose& eventType) noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    System::UnusedFunction(eventType);
}
