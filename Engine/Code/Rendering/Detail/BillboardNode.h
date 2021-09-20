// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.0.3 (2019/07/24 10:27)

#ifndef RENDERING_DETAIL_BILLBOARD_NODE_H
#define RENDERING_DETAIL_BILLBOARD_NODE_H

#include "Rendering/SceneGraph/Camera.h"
#include "Rendering/SceneGraph/Node.h"

EXPORT_SHARED_PTR(Rendering, BillboardNodeImpl, RENDERING_DEFAULT_DECLARE);

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

namespace Rendering
{
    // ����Ƶ�ģ�Ϳռ���е�(0,1,0)����ʸ��
    // ��ѡ��Ϊ��ת�Ĺ���Ƶ��ᡣ
    class RENDERING_DEFAULT_DECLARE BillboardNode : public Node
    {
    public:
        void Swap(BillboardNode& rhs) noexcept;

    public:
        TYPE_DECLARE(BillboardNode);
        using ClassShareType = CoreTools::CopyUnsharedClasses;
        ~BillboardNode() noexcept = default;
        BillboardNode(const BillboardNode& rhs);
        BillboardNode& operator=(const BillboardNode& rhs);
        BillboardNode(BillboardNode&& rhs) noexcept;
        BillboardNode& operator=(BillboardNode&& rhs) noexcept;
        using ParentType = Node;

    public:
        explicit BillboardNode(const CameraSharedPtr& camera);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(BillboardNode);
        CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

        // ����ƶ��������ͷ��
        void AlignTo(const CameraSharedPtr& camera);

        ControllerInterfaceSharedPtr Clone() const override;

        const ConstCameraSharedPtr GetCamera() const;

    private:
        // �Լ��θ��µ�֧�֡�
        bool UpdateWorldData(double applicationTime) override;

    private:
        using ImplPtr = std::shared_ptr<ImplType>;
    private:
        ImplPtr impl;
    };
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
    CORE_TOOLS_STREAM_REGISTER(BillboardNode);
#include STSTEM_WARNING_POP
    CORE_TOOLS_SHARED_PTR_DECLARE(BillboardNode);
}
#include STSTEM_WARNING_POP
#endif  // RENDERING_DETAIL_BILLBOARD_NODE_H
