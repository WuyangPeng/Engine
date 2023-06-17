///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.9.0.12 (2023/06/13 16:49)

#include "Toolset/Framework/FrameworkToolset/FrameworkToolsetExport.h"

#include "OpenGLGlutFrameBuild.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutFrameBuildDetail.h"
#include "Framework/OpenGLGlutFrame/OpenGLGlutProcessDetail.h"

CLASS_INVARIANT_STUB_DEFINE(FrameworkToolset, OpenGLGlutFrameBuild)

namespace FrameworkToolset
{
    template class Framework::OpenGLGlutFrameBuild<Framework::OpenGLGlutProcessInterface>;
}
