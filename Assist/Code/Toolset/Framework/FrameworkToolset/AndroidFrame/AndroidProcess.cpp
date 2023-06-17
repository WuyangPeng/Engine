///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:54)

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
