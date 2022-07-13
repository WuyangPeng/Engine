///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/12 15:46)

#include "Example/Network/NetworkExample/NetworkExampleExport.h"

#include "Placeholder.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

NetworkExample::Placeholder::Placeholder() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(NetworkExample, Placeholder)
