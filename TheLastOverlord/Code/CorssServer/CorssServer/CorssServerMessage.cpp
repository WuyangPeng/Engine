/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/17 19:10)

#include "CorssServer/CorssServerCore/Helper/CorssServerCoreClassInvariantMacro.h"
#include "CorssServer/CorssServerMiddleLayer/Input/InputManagerDetail.h"
#include "CorssServerMessage.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

CorssServer::CorssServerMessage::CorssServerMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ delta, environmentDirectory }, alloc{ ConsoleAlloc::Create() }
{
    CORSS_SERVER_CORE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CorssServer, CorssServerMessage)
