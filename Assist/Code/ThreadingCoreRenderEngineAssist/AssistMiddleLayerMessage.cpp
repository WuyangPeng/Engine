///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/06/30 13:54)

#include "AssistMiddleLayerMessage.h"
#include "Helper/AssistClassInvariantMacro.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

ThreadingCoreRenderEngineAssist::AssistMiddleLayerMessage::AssistMiddleLayerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, alloc{ ConsoleAlloc::Create() }
{
    ASSIST_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(ThreadingCoreRenderEngineAssist, AssistMiddleLayerMessage)
