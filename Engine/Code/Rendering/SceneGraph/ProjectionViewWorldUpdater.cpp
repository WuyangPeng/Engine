///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/17 19:32)

#include "Rendering/RenderingExport.h"

#include "ProjectionViewWorldUpdater.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::ProjectionViewWorldUpdater::ProjectionViewWorldUpdater(CoreTools::DisableNotThrow disableNotThrow) noexcept
{
    System::UnusedFunction(disableNotThrow);

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectionViewWorldUpdater)

std::shared_ptr<Rendering::Camera> Rendering::ProjectionViewWorldUpdater::GetCamera() noexcept
{
    return nullptr;
}

void Rendering::ProjectionViewWorldUpdater::Update() noexcept
{
}

void Rendering::ProjectionViewWorldUpdater::Unsubscribe(MAYBE_UNUSED const std::shared_ptr<Visual>& visual) noexcept
{
}

void Rendering::ProjectionViewWorldUpdater::Subscribe(MAYBE_UNUSED const std::shared_ptr<Visual>& visual) noexcept
{
}
