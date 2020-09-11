// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/22 15:07)

#ifndef RENDERING_SCENE_GRAPH_VISUAL_H
#define RENDERING_SCENE_GRAPH_VISUAL_H

#include "Rendering/RenderingDll.h"

#include "Spatial.h"
#include "Flags/VisualFlags.h"
#include "Rendering/Resources/IndexBuffer.h"
#include "Rendering/Resources/VertexBuffer.h"
#include "Rendering/Resources/VertexFormat.h"
#include "Rendering/Shaders/VisualEffectInstance.h"

RENDERING_EXPORT_SHARED_PTR(VisualImpl);
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)
namespace Rendering
{
    class VisualEffectInstance;
    class Culler;

    class RENDERING_DEFAULT_DECLARE Visual : public Spatial
    {
    public:
        COPY_UNSHARE_CLASSES_TYPE_DECLARE(Visual);
        using ParentType = Spatial;
        using VisualSmartPointer = std::shared_ptr<ClassType>;
        using ConstVisualSmartPointer = std::shared_ptr<const ClassType>;
        using APoint = Mathematics::FloatAPoint;

    public:
        explicit Visual(VisualPrimitiveType type = VisualPrimitiveType::None);
        Visual(VisualPrimitiveType type, const VertexFormatSmartPointer& vertexformat, const VertexBufferSmartPointer& vertexbuffer, const IndexBufferSmartPointer& indexbuffer);
        ~Visual();
        Visual(Visual&&) = default;
        Visual& operator=(Visual&&) = default;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        VisualPrimitiveType GetPrimitiveType() const;

        void SetVertexFormat(const VertexFormatSmartPointer& vertexformat);
        ConstVertexFormatSmartPointer GetConstVertexFormat() const;
        VertexFormatSmartPointer GetVertexFormat();

        void SetVertexBuffer(const VertexBufferSmartPointer& vertexbuffer);
        ConstVertexBufferSmartPointer GetConstVertexBuffer() const;
        VertexBufferSmartPointer GetVertexBuffer();

        void SetIndexBuffer(const IndexBufferSmartPointer& indexbuffer);
        ConstIndexBufferSmartPointer GetConstIndexBuffer() const;
        IndexBufferSmartPointer GetIndexBuffer();

        const FloatBound& GetModelBound() const noexcept;
        FloatBound& GetModelBound() noexcept;

        // 存取绘制对象的视觉效果。
        void SetEffectInstance(const VisualEffectInstanceSmartPointer& effect) noexcept;
        const ConstVisualEffectInstanceSmartPointer GetConstEffectInstance() const noexcept;
        const VisualEffectInstanceSmartPointer GetEffectInstance() noexcept;

        virtual void UpdateModelSpace(VisualUpdateType type);

    protected:
        virtual void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        // 支持分级裁剪。
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        // 对几何更新的支持。
        void UpdateWorldBound() override;

        ConstVisualSmartPointer GetSmartPointer() const;

        void CloneData(const Visual& rhs);
        void CloneIndexBuffer(const Visual& rhs);
        void CloneVertexBuffer(const Visual& rhs);
        void CloneVertexFormat(const Visual& rhs);

    private:
        IMPL_TYPE_DECLARE(Visual);
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Visual);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Sixth, Visual);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SCENE_GRAPH_VISUAL_H
