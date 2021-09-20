// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/22 13:45)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "ModelViewControllerMiddleLayerContainer.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"   
#include "Framework/MiddleLayer/ModelViewControllerMiddleLayerContainerDetail.h"
#include "Framework/Application/Flags/ApplicationTrait.h"
#include "Framework/MiddleLayer/ModelMiddleLayer.h"
#include "Framework/MiddleLayer/ViewMiddleLayer.h"
#include "Framework/MiddleLayer/ControllerMiddleLayerDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, ModelViewControllerMiddleLayerContainer)

namespace FrameworkToolset
{
	template
	class Framework::ModelViewControllerMiddleLayerContainer<Framework::WindowApplicationTrait, Framework::ModelMiddleLayer,
															 Framework::ViewMiddleLayer, Framework::ControllerMiddleLayer>;
}