/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 12:59)

#include "Player.h"
#include "System/Helper/Tools.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateMachineDetail.h"

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
