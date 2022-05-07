///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/21 18:25)

#ifndef RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H
#define RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/Buffer.h"
#include "Rendering/Shaders/ShaderParameters.h"

#include <map>

namespace Rendering
{
    template <typename TextureFlags, typename PdrTextureType>
    class ShaderManagement
    {
    public:
        using ClassType = ShaderManagement<TextureFlags, PdrTextureType>;
        using ConstTextureSharedPtr = std::shared_ptr<const TextureFlags>;
        using PdrTextureSharedPtr = std::shared_ptr<PdrTextureType>;
        using RendererWeakPtr = std::weak_ptr<Renderer>;

    public:
        explicit ShaderManagement(const RendererWeakPtr& renderer);

        CLASS_INVARIANT_DECLARE;

        // 1D、2D、3D纹理管理。纹理对象必须是已经由应用程序代码分配。
        void Bind(const ConstTextureSharedPtr& texture);
        void Unbind(const ConstTextureSharedPtr& texture);

        void Enable(const ConstTextureSharedPtr& texture, const ShaderParameters& parameters);
        void Disable(const ConstTextureSharedPtr& texture, const ShaderParameters& parameters);

        NODISCARD void* Lock(const ConstTextureSharedPtr& texture, int level, BufferLocking mode);
        void Unlock(const ConstTextureSharedPtr& texture, int level);
        void Update(const ConstTextureSharedPtr& texture, int level);

        NODISCARD PdrTextureSharedPtr GetResource(const ConstTextureSharedPtr& buffer);

    private:
        using TextureMap = std::map<ConstTextureSharedPtr, PdrTextureSharedPtr>;

    private:
        RendererWeakPtr renderer;
        TextureMap textures;
    };
}

#endif  // RENDERING_RENDERERS_NON_CUBE_TEXTURE_MANAGEMENT_H
