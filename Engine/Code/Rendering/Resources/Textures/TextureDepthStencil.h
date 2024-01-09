/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:55)

#ifndef RENDERING_RESOURCES_TEXTURE_DEPTH_STENCIL_H
#define RENDERING_RESOURCES_TEXTURE_DEPTH_STENCIL_H

#include "Rendering/RenderingDll.h"

#include "Texture2D.h"

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureDepthStencil : public Texture2D
    {
    public:
        using ClassType = TextureDepthStencil;
        using ParentType = Texture2D;

    public:
        TextureDepthStencil(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, bool createStorage = true);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureDepthStencil);

        NODISCARD TextureSharedPtr Clone() const override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        void MakeShaderInput() noexcept;
        NODISCARD bool IsShaderInput() const noexcept;

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    private:
        bool shaderInput;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(TextureDepthStencil);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(TextureDepthStencil);
}

#endif  // RENDERING_RESOURCES_TEXTURE_DEPTH_STENCIL_H