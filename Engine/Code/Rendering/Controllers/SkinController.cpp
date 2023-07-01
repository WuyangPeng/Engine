///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:07)

#include "Rendering/RenderingExport.h"

#include "SkinController.h"
#include "Detail/SkinControllerImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h" 
#include "Rendering/SceneGraph/Visual.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, SkinController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SkinController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, SkinController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SkinController)

Rendering::SkinController::SkinController(int numVertices, int numBones)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ numVertices, numBones }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SkinController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController, GetNumVertices, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SkinController, GetNumBones, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, SkinController, GetBones, int, Rendering::ConstNodeSharedPtr)

float Rendering::SkinController::GetWeights(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWeights(bonesIndex, verticesIndex);
}

Rendering::SkinController::APoint Rendering::SkinController::GetOffsets(int bonesIndex, int verticesIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetOffsets(bonesIndex, verticesIndex);
}

void Rendering::SkinController::SetBones(int bonesIndex, const ConstNodeSharedPtr& node)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetBones(bonesIndex, node);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, SkinController, SetBones, std::vector<CoreTools::ConstObjectAssociated<Node>>, void)

void Rendering::SkinController::SetWeights(int bonesIndex, int verticesIndex, float weights)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetWeights(bonesIndex, verticesIndex, weights);
}

void Rendering::SkinController::SetWeights(int bonesIndex, const std::vector<float>& weights)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetWeights(bonesIndex, weights);
}

void Rendering::SkinController::SetOffsets(int bonesIndex, int verticesIndex, const APoint& offsets)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetOffsets(bonesIndex, verticesIndex, offsets);
}

void Rendering::SkinController::SetOffsets(int bonesIndex, const std::vector<APoint>& offsets)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetOffsets(bonesIndex, offsets);
}

Rendering::ControllerInterfaceSharedPtr Rendering::SkinController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ControllerInterfaceSharedPtr{ std::make_shared<ClassType>(*this) };
}

bool Rendering::SkinController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (ParentType::Update(applicationTime))
    {
        // 访问该顶点缓冲器来存储混合目标。
        auto visual = dynamic_cast<Visual*>(GetControllerObject());
        if (visual != nullptr)
        {
            auto vertexBuffer = visual->GetVertexBuffer();

            if (vertexBuffer)
            {
                RENDERING_ASSERTION_2(impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "控制器必须和缓冲器具有相同数量的顶点\n");

                // 皮肤顶点在骨骼世界坐标系统计算，所以视觉世界变换必须为单位。
                visual->SetWorldTransform(TransformF{});

                // 计算的皮肤顶点位置。
                for (auto vertex = 0; vertex < impl->GetNumVertices(); ++vertex)
                {
                    auto position = Mathematics::APointF{};
                    for (auto bone = 0; bone < impl->GetNumBones(); ++bone)
                    {
                        const auto weight = impl->GetWeights(bone, vertex);
                        if (Mathematics::MathF::GetZeroTolerance() < Mathematics::MathF::FAbs(weight))
                        {
                            const auto offset = impl->GetOffsets(bone, vertex);
                            const auto worldOffset = impl->GetBones(bone)->GetWorldTransform() * offset;
                            position += weight * worldOffset;
                        }
                    }
                }

                visual->UpdateModelSpace(VisualUpdateType::Normals);
 

                return true;
            }
        }
    }

    return false;
}

void Rendering::SkinController::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);
}

void Rendering::SkinController::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::SetObject(object);
}

Rendering::SkinController::SkinController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::SkinController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    int size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::SkinController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::SkinController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::SkinController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::SkinController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::SkinController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::SkinController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
