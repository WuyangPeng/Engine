///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 14:23)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ModelViewControllerMiddleLayerContainer.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"
#include "Framework/MiddleLayer/ViewMiddleLayer.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ModelViewControllerMiddleLayerContainer)

namespace FrameworkToolset
{
    template class Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::ModelMiddleLayer, Framework::ViewMiddleLayer, Framework::ControllerMiddleLayer>;
}