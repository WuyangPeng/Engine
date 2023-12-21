///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:53)

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

    // 计算广告牌的世界变换基于其父世界变换及其局部变换。
    // 请注意，你不应该调用Node::UpdateWorldData，因为该函数更新其子节点。
    // 直到广告牌与摄像机对准一个BillboardNode，子节点不能更新。
    Spatial::UpdateWorldData(applicationTime);

    auto camera = impl->GetCamera();

    if (camera)
    {
        // 相机逆变换到广告牌的模型空间。
        auto modelPosition = GetWorldTransform().GetInverseTransform() * camera->GetPosition();

        // 要对齐广告牌，相机广告牌的模型空间的xz平面的投影决定对广告牌的模型y轴旋转的角度。
        // 如果投影的照相机是在模型上的轴 (x = 0 和 z = 0)，
        // ATan2返回零（而非NaN的），因此没有必要捕获此退化情况，并分别进行处理。
        auto angle = Mathematics::MathF::ATan2(modelPosition[0], modelPosition[2]);
        const Mathematics::MatrixF orient{ Mathematics::AVectorF::GetUnitY(), angle };

        auto transform = GetWorldTransform();
        const auto rotate = transform.GetRotate() * orient;
        transform.SetRotate(rotate);
        SetWorldTransformOnUpdate(transform);
    }

    // 现在的广告牌方向可以告诉子节点进行更新。
    return ParentType::UpdateChildWorldData(applicationTime);
}
