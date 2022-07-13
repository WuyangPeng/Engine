///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/04 19:28)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "AndroidProcess.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackInterface.h"
#include "Framework/AndroidFrame/AndroidProcessDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, AndroidProcess)

namespace FrameworkToolset
{
    template class Framework::AndroidProcess<Framework::AndroidCallBackInterface>;
}
