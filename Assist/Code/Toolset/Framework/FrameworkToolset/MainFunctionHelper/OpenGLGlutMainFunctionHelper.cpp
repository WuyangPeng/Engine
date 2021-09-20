// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.3.0.1 (2020/05/22 13:45)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "OpenGLGlutMainFunctionHelper.h" 
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/MainFunctionHelper/OpenGLGlutMainFunctionHelperDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, OpenGLGlutMainFunctionHelper)

namespace FrameworkToolset
{
	template
	class Framework::OpenGLGlutMainFunctionHelper<Framework::OpenGLGlutFrameBuild, Framework::OpenGLGlutProcessInterface>;
}


