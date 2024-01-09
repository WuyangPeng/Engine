///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/24 13:49)

#ifndef RENDERING_CONTROLLERS_SKIN_CONTROLLER_H
#define RENDERING_CONTROLLERS_SKIN_CONTROLLER_H

#include "Rendering/RenderingDll.h"

#include "Controller.h"
#include "CoreTools/ObjectSystems/ConstObjectAssociated.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/SceneGraph/Node.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(SkinController, SkinControllerImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE SkinController : public Controller
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(SkinController);
        using ParentType = Controller;

        using APoint = Mathematics::APointF;
        using BaseRendererSharedPtr = std::shared_ptr<BaseRenderer>;
        using ConstObjectAssociated = CoreTools::ConstObjectAssociated<Node>;
        using ConstObjectAssociatedContainer = std::vector<ConstObjectAssociated>;

    public:
        // ����͹�������Ŀ�ڶ�����������ǹ̶��ġ�
        SkinController(int numVertices, int numBones, const BaseRendererSharedPtr& baseRenderer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(SkinController);

        NODISCARD int GetNumVertices() const noexcept;
        NODISCARD int GetNumBones() const noexcept;

        NODISCARD ConstNodeSharedPtr GetBones(int bonesIndex) const;
        NODISCARD float GetWeights(int bonesIndex, int verticesIndex) const;
        NODISCARD APoint GetOffsets(int bonesIndex, int verticesIndex) const;

        // ���ù��캯����������ʹ����Щ�����������ݡ�
        void SetBones(int bonesIndex, const ConstNodeSharedPtr& node);
        void SetWeights(int bonesIndex, int verticesIndex, float weights);
        void SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets);

        void SetBones(const ConstObjectAssociatedContainer& bones);
        void SetWeights(int bonesIndex, const std::vector<float>& weights);
        void SetOffsets(int bonesIndex, const std::vector<APoint>& offsets);

        // �������¡�Ӧ�ó���ʱ���Ժ���Ϊ��λ��
        NODISCARD bool Update(double applicationTime) override;

        NODISCARD ControllerSharedPtr Clone() const override;

        void SetController(const ControllerSharedPtr& object) override;
        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(SkinController);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(SkinController);
}

#endif  // RENDERING_CONTROLLERS_SKIN_CONTROLLER_H
