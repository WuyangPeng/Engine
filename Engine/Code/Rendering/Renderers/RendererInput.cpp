///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:50)

#include "Rendering/RenderingExport.h"

#include "RendererFactory.h"
#include "RendererInput.h"
#include "Detail/RendererInputImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

Rendering::RendererInput::RendererInput(RendererTypes type)
    : impl{ CoreTools::ImplCreateUseFactory::Default, type }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererInput)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RendererInput, SetWindowID, int, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, RendererInput, SetWindowHandle, HWnd, void)