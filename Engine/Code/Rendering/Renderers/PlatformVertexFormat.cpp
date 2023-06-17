///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 12:49)

#include "Rendering/RenderingExport.h"

#include "PlatformVertexFormat.h"
#include "Renderer.h"
#include "Detail/PlatformVertexFormatImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::PlatformVertexFormat::PlatformVertexFormat(Renderer* renderer, const VertexFormat* vertexFormat)
    : impl{ CoreTools::ImplCreateUseFactory::Default, renderer, vertexFormat }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, PlatformVertexFormat)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Enable, Renderer*, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PlatformVertexFormat, Disable, Renderer*, void)