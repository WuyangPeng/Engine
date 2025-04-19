///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 14:22)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "WindowMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, WindowMessage)

namespace Framework
{
    template class Framework::WindowMessage<Framework::MiddleLayerInterface>;
}
