///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 19:05)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "WindowMessage.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/MiddleLayerInterface.h"
#include "Framework/WindowProcess/WindowMessageDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, WindowMessage)

namespace FrameworkToolset
{
    template class Framework::WindowMessage<Framework::MiddleLayerInterface>;
}
