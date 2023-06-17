///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 12:50)

#include "Rendering/RenderingExport.h"

#include "RendererInputData.h"
#include "Detail/RendererInputDataImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MainFunctionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Threading/Mutex.h"
#include "CoreTools/Threading/ScopedMutex.h"

SINGLETON_GET_PTR_DEFINE(Rendering, RendererInputData);

Rendering::RendererInputData::RendererInputDataUniquePtr Rendering::RendererInputData::rendererInputData{};

void Rendering::RendererInputData::Create()
{
    rendererInputData = std::make_unique<Rendering::RendererInputData>(RendererInputDataCreate::Init);
}

void Rendering::RendererInputData::Destroy() noexcept
{
    rendererInputData.reset();
}

Rendering::RendererInputData::RendererInputData([[maybe_unused]] RendererInputDataCreate rendererInputDataCreate)
    : impl{ CoreTools::DisableNotThrow::Disable }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, RendererInputData)

void Rendering::RendererInputData::Rebuild(RendererTypes type)
{
    SINGLETON_MUTEX_ENTER_MEMBER;

    RENDERING_CLASS_IS_VALID_1;

    impl->Rebuild(type);
}
