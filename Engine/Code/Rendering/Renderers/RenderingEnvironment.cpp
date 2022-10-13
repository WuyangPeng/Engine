///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.2 (2022/09/04 21:53)

#include "Rendering/RenderingExport.h"

#include "RenderingEnvironment.h"
#include "Detail/RenderingEnvironmentFactory.h"
#include "Detail/RenderingEnvironmentImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, RenderingEnvironment)

Rendering::RenderingEnvironment::RenderingEnvironment(const EnvironmentParameter& environmentParameter, const RendererParameter& rendererParameter)
    : impl{ CoreTools::ImplCreateUseFactory::Default, environmentParameter, rendererParameter }
{
    impl->InitEnvironment();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RenderingEnvironment)

void Rendering::RenderingEnvironment::Release()
{
    RENDERING_CLASS_IS_VALID_9;

    impl->Release();
}

Rendering::RenderingDevice Rendering::RenderingEnvironment::GetRenderingDevice() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetRenderingDevice();
}
