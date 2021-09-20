///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	最后的霸王版本：0.7.0.1 (2021/02/18 14:35)

#include "Helper/TheLastOverlordClassInvariantMacro.h"
#include "TheLastOverlordMiddleLayerMessage.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "Framework/MiddleLayer/EngineMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

TheLastOverlord::TheLastOverlordMiddleLayerMessage::TheLastOverlordMiddleLayerMessage(int64_t delta)
    : ParentType{ delta }, m_Alloc{ CoreTools::DisableNotThrow::Disable }
{
    THE_LAST_OVERLORD_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(TheLastOverlord, TheLastOverlordMiddleLayerMessage)
