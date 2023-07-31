///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/25 16:27)

#include "Status/StatusExport.h"

#include "Placeholder.h"
#include "Status/Helper/StatusClassInvariantMacro.h"

Status::Placeholder::Placeholder() noexcept
{
    STATUS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Status, Placeholder)
