/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/17 19:45)

#include "PlayerServer/PlayerServerCore/Helper/PlayerServerCoreClassInvariantMacro.h"
#include "PlayerServer/PlayerServerMiddleLayer/Input/InputManagerDetail.h"
#include "PlayerServerMessage.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

PlayerServer::PlayerServerMessage::PlayerServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, alloc{ ConsoleAlloc::Create() }
{
    PLAYER_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(PlayerServer, PlayerServerMessage)
