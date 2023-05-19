///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.9.0.8 (2023/05/10 18:18)

#include "Toolset/Network/NetworkToolset/NetworkToolsetExport.h"

#include "Placeholder.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

NetworkToolset::Placeholder::Placeholder() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(NetworkToolset, Placeholder)
