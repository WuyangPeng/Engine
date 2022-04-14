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
EXPORT_SHARED_PTR(Rendering, VisualImpl, RENDERING_DEFAULT_DECLARE);
 
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
        void Swap(Visual& rhs) noexcept;
         
             public:
                 TYPE_DECLARE(Visual);
                 using ClassShareType = CoreTools::CopyUnsharedClasses;
                 ~Visual() noexcept;
                 Visual(const Visual& rhs);
                 Visual& operator=(const Visual& rhs);
                 Visual(Visual&& rhs) noexcept;
                 Visual& operator=(Visual&& rhs) noexcept;
        using ParentType = Spatial;
        using VisualSharedPtr = std::shared_ptr<ClassType>;
        using ConstVisualSharedPtr = std::shared_ptr<const ClassType>;
        using APoint = Mathematics::APointF;

    public:
        explicit Visual(VisualPrimitiveType type = VisualPrimitiveType::None);
        Visual(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);
        
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        VisualPrimitiveType GetPrimitiveType() const noexcept;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat) noexcept;
        ConstVertexFormatSharedPtr GetConstVertexFormat() const noexcept;
        VertexFormatSharedPtr GetVertexFormat() noexcept;

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer) noexcept;
        ConstVertexBufferSharedPtr GetConstVertexBuffer() const noexcept;
        VertexBufferSharedPtr GetVertexBuffer() noexcept;

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer) noexcept;
        ConstIndexBufferSharedPtr GetConstIndexBuffer() const noexcept;
        IndexBufferSharedPtr GetIndexBuffer() noexcept;

        const BoundF& GetModelBound() const noexcept;
        BoundF& GetModelBound() noexcept;

        // 存取绘制对象的视觉效果。
        void SetEffectInstance(const VisualEffectInstanceSharedPtr& effect) noexcept;
        const ConstVisualEffectInstanceSharedPtr GetConstEffectInstance() const noexcept;
        const VisualEffectInstanceSharedPtr GetEffectInstance() noexcept;

        virtual void UpdateModelSpace(VisualUpdateType type);

    protected:
        virtual void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        // 支持分级裁剪。
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        // 对几何更新的支持。
        void UpdateWorldBound() override;

        ConstVisualSharedPtr GetSharedPtr() const;

        void CloneData(const Visual& rhs);
        void CloneIndexBuffer(const Visual& rhs);
        void CloneVertexBuffer(const Visual& rhs);
        void CloneVertexFormat(const Visual& rhs);

    private:
        using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(Visual);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE( Visual);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SCENE_GRAPH_VISUAL_H
