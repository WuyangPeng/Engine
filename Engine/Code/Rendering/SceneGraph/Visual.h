/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.2 (2023/12/20 09:55)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_H
#define RENDERING_SCENE_GRAPH_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Rendering/LocalEffects/ConstantColorEffect.h"
#include "Rendering/LocalEffects/VisualEffect.h"
#include "Rendering/Resources/Buffers/IndexBuffer.h"
#include "Rendering/Resources/Buffers/VertexBuffer.h"
#include "Rendering/Resources/Buffers/VertexFormat.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(Visual, VisualImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE Visual : public Spatial
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(Visual);
        using ParentType = Spatial;

        using VisualSharedPtr = std::shared_ptr<ClassType>;
        using ConstVisualSharedPtr = std::shared_ptr<const ClassType>;
        using VisualEffectSharedPtr = std::shared_ptr<VisualEffect>;
        using APoint = Mathematics::APointF;
        using BoundingSphere = Mathematics::BoundingSphereF;

    public:
        explicit Visual(const std::string& name);
        Visual(const std::string& name, const VertexFormatSharedPtr& vertexFormat, const VertexBufferSharedPtr& vertexBuffer, const IndexBufferSharedPtr& indexBuffer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD IndexFormatType GetPrimitiveType() const;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexFormat) noexcept;
        NODISCARD ConstVertexFormatSharedPtr GetConstVertexFormat() const noexcept;
        NODISCARD VertexFormatSharedPtr GetVertexFormat() noexcept;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexBuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexBuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        NODISCARD const BoundingSphere& GetModelBound() const noexcept;
        NODISCARD BoundingSphere& GetModelBound() noexcept;

        virtual void UpdateModelSpace(VisualUpdateType type);

        void SetVisualEffect(const VisualEffectSharedPtr& visualEffect) noexcept;
        NODISCARD ConstVisualEffectSharedPtr GetConstVisualEffect() const noexcept;
        NODISCARD VisualEffectSharedPtr GetVisualEffect() noexcept;

        void UpdateModelBound();
        void UpdateModelNormals();

    protected:
        // 支持分级裁剪。
        void GetVisibleSet(Culler& culler, const CameraSharedPtr& camera, bool noCull) override;

    private:
        // 对几何更新的支持。
        void UpdateWorldBound() override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(Visual);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(Visual);
}

#endif  // RENDERING_SCENE_GRAPH_VISUAL_H
