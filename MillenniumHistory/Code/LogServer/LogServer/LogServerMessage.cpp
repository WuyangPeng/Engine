/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 20:42)

#include "LogServer//LogServerCore/Helper/LogServerCoreClassInvariantMacro.h"
#include "LogServer/LogServerMiddleLayer/Input/InputManagerDetail.h"
#include "LogServerMessage.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

LogServer::LogServerMessage::LogServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, alloc{ ConsoleAlloc::Create() }
{
    LOG_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(LogServer, LogServerMessage)