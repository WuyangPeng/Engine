/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.6 (2024/02/21 14:11)

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