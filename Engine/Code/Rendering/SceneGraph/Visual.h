///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:11)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_H
#define RENDERING_SCENE_GRAPH_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Flags/VisualFlags.h"
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
        using APoint = Mathematics::APointF;

    public:
        explicit Visual(VisualPrimitiveType type);
        Visual(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);
        ~Visual() noexcept = default;

        Visual(const Visual& rhs);
        Visual& operator=(const Visual& rhs);
        Visual(Visual&& rhs) noexcept;
        Visual& operator=(Visual&& rhs) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        NODISCARD VisualPrimitiveType GetPrimitiveType() const noexcept;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept;
        NODISCARD ConstVertexFormatSharedPtr GetConstVertexFormat() const noexcept;
        NODISCARD VertexFormatSharedPtr GetVertexFormat() noexcept;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept;
        NODISCARD ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        NODISCARD VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept;
        NODISCARD ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        NODISCARD IndexBufferSharedPtr GetIndexBuffer() noexcept;

        NODISCARD const Mathematics::BoundingSphereF& GetModelBound() const noexcept;
        NODISCARD Mathematics::BoundingSphereF& GetModelBound() noexcept;

        virtual void UpdateModelSpace(MAYBE_UNUSED VisualUpdateType type);

        NODISCARD std::shared_ptr<VisualEffect> GetEffect() noexcept;
        void SetEffect(const std::shared_ptr<VisualEffect>& visualEffect) noexcept;
        void SetWorldTransformIsCurrent(bool cond) noexcept;
        virtual void UpdateModelBound();
        virtual void UpdateModelNormals() noexcept;

    protected:
        void ComputeBounding(const std::vector<APoint>& positions);

        // 支持分级裁剪。
        void GetVisibleSet(Culler& culler, MAYBE_UNUSED bool noCull) override;

    private:
        // 对几何更新的支持。
        void UpdateWorldBound() override;

        NODISCARD ConstVisualSharedPtr GetSharedPtr() const;

        void CloneData(const Visual& rhs);
        void CloneIndexBuffer(const Visual& rhs);
        void CloneVertexBuffer(const Visual& rhs);
        void CloneVertexFormat(const Visual& rhs);

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
