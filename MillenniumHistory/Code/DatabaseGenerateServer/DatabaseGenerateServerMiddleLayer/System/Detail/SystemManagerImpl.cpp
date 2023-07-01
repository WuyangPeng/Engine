///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/19 21:51)

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/DatabaseGenerateServerMiddleLayerExport.h"

#include "DatabaseGenerateServer/DatabaseGenerateServerMiddleLayer/Helper/DatabaseGenerateServerMiddleLayerClassInvariantMacro.h"
#include "SystemManagerImpl.h"

DatabaseGenerateServerMiddleLayer::SystemManagerImpl::SystemManagerImpl() noexcept
{
    DATABASE_GENERATE_SERVER_MIDDLE_LAYER_CLASS_IS_VALID_CONST_9;
}

CLASS_INVARIANT_STUB_DEFINE(DatabaseGenerateServerMiddleLayer, SystemManagerImpl)

bool DatabaseGenerateServerMiddleLayer::SystemManagerImpl::Initialize() noexcept
{
    return true;
}
