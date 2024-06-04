/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 12:58)

#include "EmptyStates.h"
#include "OpenStates.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/StateMachineManager/StateEntityDetail.h"
#include "CoreTools/StateMachineManager/StateMachineBaseDetail.h"

CORE_TOOLS_RTTI_DEFINE(CoreTools, EmptyStates)

CoreTools::EmptyStates::EmptyStates() noexcept
    : ParentType{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, EmptyStates)

CoreTools::EmptyStates::StateSharedPtr CoreTools::EmptyStates::Execute(int64_t timeInterval)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    System::UnusedFunction(timeInterval);

    return shared_from_this();
}

void CoreTools::EmptyStates::Exit() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_1;
}

CoreTools::State<CoreTools::PlayerEntity>::MessageResult CoreTools::EmptyStates::OnMessage(const Telegram& telegram)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    switch (telegram.GetMessageType())
    {
        case States::Empty:
            return { shared_from_this(), false };
        case States::Open:
            return { MakeState<OpenStates>(), true };
        case States::Stopped:
        case States::Playing:
        case States::Paused:
            return { shared_from_this(), true };
        case States::Previous:
            return { GetPossiblePreviousState(), true };
        default:
            break;
    }

    return { shared_from_this(), true };
}

void CoreTools::EmptyStates::DoEnter() noexcept
{
}
