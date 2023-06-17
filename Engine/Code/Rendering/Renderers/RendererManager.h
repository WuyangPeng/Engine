///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:37)

#ifndef RENDERING_RENDERERS_RENDERER_MANAGE_H
#define RENDERING_RENDERERS_RENDERER_MANAGE_H

#include "Rendering/RenderingDll.h"

#include "RenderersFwd.h"
#include "CoreTools/Base/SingletonDetail.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/SingletonMacro.h"
#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/Shaders/ShadersFwd.h"

RENDERING_EXPORT_UNIQUE_PTR(RendererManager);
RENDERING_NON_COPY_EXPORT_IMPL(RendererManagerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RendererManager : public CoreTools::Singleton<RendererManager>
    {
    public:
        NON_COPY_TYPE_DECLARE(RendererManager);
        using ParentType = Singleton<RendererManager>;
        using RendererPtr = std::shared_ptr<Renderer>;
        using ConstVertexFormatSharedPtr = std::shared_ptr<const VertexFormat>;
        using ConstVertexBufferSharedPtr = std::shared_ptr<const VertexBuffer>;
        using ConstIndexBufferSharedPtr = std::shared_ptr<const IndexBuffer>;
        using ConstTexture1DSharedPtr = std::shared_ptr<const Texture1D>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using ConstTexture3DSharedPtr = std::shared_ptr<const Texture3D>;
        using ConstTextureCubeSharedPtr = std::shared_ptr<const TextureCube>;
        using ConstDrawTargetSharedPtr = std::shared_ptr<const DrawTarget>;
        using ConstVertexShaderSharedPtr = std::shared_ptr<const VertexShader>;
        using ConstPixelShaderSharedPtr = std::shared_ptr<const PixelShader>;

    private:
        enum class RendererManagerCreate
        {
            Init,
        };

    public:
        explicit RendererManager(RendererManagerCreate rendererManagerCreate);

        static void Create();
        static void Destroy() noexcept;

        SINGLETON_GET_PTR_DECLARE(RendererManager);

        CLASS_INVARIANT_DECLARE;

        int64_t Insert(RendererPtr ptr);
        bool Erase(int64_t rendererID);

        // ��Դ��������Դ������Ϊ�����ʽ�����㻺������������������
        // ����1D��2D��3D�������壩��
        // ��ȾĿ�꣬������ɫ����������ɫ��������ִ�����²�����

        // BindAll: ������Ӧ��ϵͳ�е�������Ⱦ��������������Դ��
        // UnbindAll:  ���ٵ���Դ��Ӧ�����������������Ⱦ������Դ��Ŀ�ꡣ
        // ����������õĶ��������������
        // UpdateAll:  ���£���ʩ�ӵ�������Դ������Ⱦ��Դ����ġ�

        void BindAll(const ConstVertexFormatSharedPtr& vertexFormat);
        void UnbindAll(const ConstVertexFormatSharedPtr& vertexFormat);

        void BindAll(const ConstVertexBufferSharedPtr& vertexBuffer);
        void UnbindAll(const ConstVertexBufferSharedPtr& vertexBuffer);
        void UpdateAll(const ConstVertexBufferSharedPtr& vertexBuffer);

        void BindAll(const ConstIndexBufferSharedPtr& indexBuffer);
        void UnbindAll(const ConstIndexBufferSharedPtr& indexBuffer);
        void UpdateAll(const ConstIndexBufferSharedPtr& indexBuffer);

        void BindAll(const ConstTexture1DSharedPtr& texture);
        void UnbindAll(const ConstTexture1DSharedPtr& texture);
        void UpdateAll(const ConstTexture1DSharedPtr& texture, int level);

        void BindAll(const ConstTexture2DSharedPtr& texture);
        void UnbindAll(const ConstTexture2DSharedPtr& texture);
        void UpdateAll(const ConstTexture2DSharedPtr& texture, int level);

        void BindAll(const ConstTexture3DSharedPtr& texture);
        void UnbindAll(const ConstTexture3DSharedPtr& texture);
        void UpdateAll(const ConstTexture3DSharedPtr& texture, int level);

        void BindAll(const ConstTextureCubeSharedPtr& texture);
        void UnbindAll(const ConstTextureCubeSharedPtr& texture);
        void UpdateAll(const ConstTextureCubeSharedPtr& texture, int face, int level);

        void BindAll(const ConstDrawTargetSharedPtr& renderTarget);
        void UnbindAll(const ConstDrawTargetSharedPtr& renderTarget);

        void BindAll(const ConstVertexShaderSharedPtr& vertexShader);
        void UnbindAll(const ConstVertexShaderSharedPtr& vertexShader);

        void BindAll(const ConstPixelShaderSharedPtr& pixelShader);
        void UnbindAll(const ConstPixelShaderSharedPtr& pixelShader);

    private:
        using RendererManagerUniquePtr = std::unique_ptr<RendererManager>;

    private:
        static RendererManagerUniquePtr rendererManager;
        PackageType impl;
    };
}

#define RENDERER_MANAGE_SINGLETON Rendering::RendererManager::GetSingleton()

#endif  // RENDERING_RENDERERS_RENDERER_MANAGE_H
