///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.5 (2022/03/31 16:02)

#ifndef RENDERING_RESOURCES_RENDER_TARGET_H
#define RENDERING_RESOURCES_RENDER_TARGET_H

#include "Rendering/RenderingDll.h"

#include "Texture2D.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Rendering/DataTypes/Flags/TextureFormat.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(RenderTarget, RenderTargetImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE RenderTarget : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(RenderTarget);
        using ParentType = Object;
        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using ConstTexture2DSharedPtr = std::shared_ptr<const Texture2D>;
        using RenderTargetSharedPtr = std::shared_ptr<ClassType>;
        using ConstRenderTargetSharedPtr = std::shared_ptr<const ClassType>;

    public:
        // ֧��Ŀ�������ȡ����ͼ��Ӳ�����������򡣡�numTargets����������1��
        RenderTarget(int numTargets, TextureFormat format, int width, int height, bool hasMipmaps, bool hasDepthStencil);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(RenderTarget);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD int GetNumTargets() const;
        NODISCARD TextureFormat GetFormat() const;
        NODISCARD int GetWidth() const;
        NODISCARD int GetHeight() const;
        NODISCARD ConstTexture2DSharedPtr GetColorTexture(int index) const;
        NODISCARD ConstTexture2DSharedPtr GetDepthStencilTexture() const noexcept;
        NODISCARD bool HasMipmaps() const noexcept;
        NODISCARD bool HasDepthStencil() const noexcept;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_STREAM_REGISTER(RenderTarget);

#include STSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(RenderTarget);
}

#endif  // RENDERING_RESOURCES_RENDER_TARGET_H
