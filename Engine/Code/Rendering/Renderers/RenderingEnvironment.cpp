///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:51)

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
