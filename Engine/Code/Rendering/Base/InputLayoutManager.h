///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/04 11:54)

#ifndef RENDERING_RENDERERS_INPUT_LAYOUT_MANAGER_H
#define RENDERING_RENDERERS_INPUT_LAYOUT_MANAGER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE InputLayoutManager
    {
    public:
        using ClassType = InputLayoutManager;

    public:
        InputLayoutManager() noexcept = default;
        virtual ~InputLayoutManager() noexcept = default;
        InputLayoutManager(const InputLayoutManager& rhs) noexcept = default;
        InputLayoutManager& operator=(const InputLayoutManager& rhs) noexcept = default;
        InputLayoutManager(InputLayoutManager&& rhs) noexcept = default;
        InputLayoutManager& operator=(InputLayoutManager&& rhs) noexcept = default;
    };
}

#endif  // RENDERING_RENDERERS_INPUT_LAYOUT_MANAGER_H
