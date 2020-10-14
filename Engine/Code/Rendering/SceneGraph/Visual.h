// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/22 15:07)

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
         COPY_UNSHARE_CLASSES_TYPE_DECLARE(Visual, DESTRUCTOR_STATEMENT);
        using ParentType = Spatial;
        using VisualSharedPtr = std::shared_ptr<ClassType>;
        using ConstVisualSharedPtr = std::shared_ptr<const ClassType>;
        using APoint = Mathematics::FloatAPoint;

    public:
        explicit Visual(VisualPrimitiveType type = VisualPrimitiveType::None);
        Visual(VisualPrimitiveType type, const VertexFormatSharedPtr& vertexformat, const VertexBufferSharedPtr& vertexbuffer, const IndexBufferSharedPtr& indexbuffer);
        
        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Visual);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        VisualPrimitiveType GetPrimitiveType() const;

        void SetVertexFormat(const VertexFormatSharedPtr& vertexformat);
        ConstVertexFormatSharedPtr GetConstVertexFormat() const;
        VertexFormatSharedPtr GetVertexFormat();

        void SetVertexBuffer(const VertexBufferSharedPtr& vertexbuffer);
        ConstVertexBufferSharedPtr GetConstVertexBuffer() const;
        VertexBufferSharedPtr GetVertexBuffer();

        void SetIndexBuffer(const IndexBufferSharedPtr& indexbuffer);
        ConstIndexBufferSharedPtr GetConstIndexBuffer() const;
        IndexBufferSharedPtr GetIndexBuffer();

        const FloatBound& GetModelBound() const noexcept;
        FloatBound& GetModelBound() noexcept;

        // ��ȡ���ƶ�����Ӿ�Ч����
        void SetEffectInstance(const VisualEffectInstanceSharedPtr& effect) noexcept;
        const ConstVisualEffectInstanceSharedPtr GetConstEffectInstance() const noexcept;
        const VisualEffectInstanceSharedPtr GetEffectInstance() noexcept;

        virtual void UpdateModelSpace(VisualUpdateType type);

    protected:
        virtual void UpdateModelBound();
        void ComputeBounding(const std::vector<APoint>& positions);

        // ֧�ַּ��ü���
        void GetVisibleSet(Culler& culler, bool noCull) override;

    private:
        // �Լ��θ��µ�֧�֡�
        void UpdateWorldBound() override;

        ConstVisualSharedPtr GetSharedPtr() const;

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
    CORE_TOOLS_SHARED_PTR_DECLARE( Visual);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_SCENE_GRAPH_VISUAL_H
