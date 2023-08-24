/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：0.9.1.3 (2023/08/21 10:43)

#include "BackgroundServer//BackgroundServerCore/Helper/BackgroundServerCoreClassInvariantMacro.h"
#include "BackgroundServer/BackgroundServerMiddleLayer/Input/InputManagerDetail.h"
#include "BackgroundServerMessage.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

BackgroundServer::BackgroundServerMessage::BackgroundServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, alloc{ ConsoleAlloc::Create() }
{
    BACKGROUND_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BackgroundServer, BackgroundServerMessage)
