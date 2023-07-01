///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/28 10:01)

#ifndef RENDERING_BASE_INPUT_LAYOUT_MANAGER_H
#define RENDERING_BASE_INPUT_LAYOUT_MANAGER_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Rendering/LocalEffects/LocalEffectsFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE InputLayoutManager
    {
    public:
        using ClassType = InputLayoutManager;

        using VertexBufferSharedPtr = std::shared_ptr<VertexBuffer>;
        using ShaderSharedPtr = std::shared_ptr<Shader>;

    public:
        InputLayoutManager() noexcept = default;
        virtual ~InputLayoutManager() noexcept = default;
        InputLayoutManager(const InputLayoutManager& rhs) noexcept = default;
        InputLayoutManager& operator=(const InputLayoutManager& rhs) noexcept = default;
        InputLayoutManager(InputLayoutManager&& rhs) noexcept = default;
        InputLayoutManager& operator=(InputLayoutManager&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual bool Unbind(const VertexBufferSharedPtr& vertexBuffer) = 0;
        NODISCARD virtual bool Unbind(const ShaderSharedPtr& vertexShader) = 0;
        virtual void UnbindAll() = 0;
        NODISCARD virtual bool HasElements() const = 0;
    };
}

#endif  // RENDERING_BASE_INPUT_LAYOUT_MANAGER_H
