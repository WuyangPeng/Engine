///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 13:53)

#include "Rendering/RenderingExport.h"

#include "BillboardNode.h"
#include "Detail/BillboardNodeImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/TransformDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, BillboardNode)

CORE_TOOLS_RTTI_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BillboardNode);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, BillboardNode);

Rendering::BillboardNode::BillboardNode(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, BillboardNode)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, BillboardNode)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, BillboardNode)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, BillboardNode)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, BillboardNode)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, BillboardNode)

Rendering::BillboardNode::BillboardNode(const CameraSharedPtr& camera)
    : ParentType{ "BillboardNode", NodeCreate::Init }, impl{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BillboardNode)

Rendering::ControllerInterfaceSharedPtr Rendering::BillboardNode::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, BillboardNode, AlignTo, CameraSharedPtr, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BillboardNode, GetCamera, Rendering::ConstCameraSharedPtr)

bool Rendering::BillboardNode::UpdateWorldData(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    // �������Ƶ�����任�����丸����任����ֲ��任��
    // ��ע�⣬�㲻Ӧ�õ���Node::UpdateWorldData����Ϊ�ú����������ӽڵ㡣
    // ֱ����������������׼һ��BillboardNode���ӽڵ㲻�ܸ��¡�
    Spatial::UpdateWorldData(applicationTime);

    auto camera = impl->GetCamera();

    if (camera)
    {
        // �����任������Ƶ�ģ�Ϳռ䡣
        auto modelPosition = GetWorldTransform().GetInverseTransform() * camera->GetPosition();

        // Ҫ�������ƣ��������Ƶ�ģ�Ϳռ��xzƽ���ͶӰ�����Թ���Ƶ�ģ��y����ת�ĽǶȡ�
        // ���ͶӰ�����������ģ���ϵ��� (x = 0 �� z = 0)��
        // ATan2�����㣨����NaN�ģ������û�б�Ҫ������˻���������ֱ���д���
        auto angle = Mathematics::MathF::ATan2(modelPosition[0], modelPosition[2]);
        const Mathematics::MatrixF orient{ Mathematics::AVectorF::GetUnitY(), angle };

        auto transform = GetWorldTransform();
        const auto rotate = transform.GetRotate() * orient;
        transform.SetRotate(rotate);
        SetWorldTransformOnUpdate(transform);
    }

    // ���ڵĹ���Ʒ�����Ը����ӽڵ���и��¡�
    return ParentType::UpdateChildWorldData(applicationTime);
}
