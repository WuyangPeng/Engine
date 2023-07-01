///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:50)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ObjectLogicManager.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MiddleLayer/ArtificialIntelligenceInterface.h"
#include "Framework/MiddleLayer/ObjectLogicInterface.h"
#include "Framework/MiddleLayer/ObjectLogicManagerDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ObjectLogicManager)

namespace FrameworkToolset
{
    template class Framework::ObjectLogicManager<Framework::ObjectLogicInterface, Framework::ArtificialIntelligenceInterface>;
}
