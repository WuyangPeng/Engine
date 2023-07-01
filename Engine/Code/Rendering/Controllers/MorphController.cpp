///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:06)

#include "Rendering/RenderingExport.h"

#include "MorphController.h"
#include "Detail/MorphControllerImpl.h"
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

CORE_TOOLS_RTTI_DEFINE(Rendering, MorphController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, MorphController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, MorphController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, MorphController)

Rendering::MorphController::MorphController(int numVertices, int numTargets, int numKeys)
    : ParentType{ CoreTools::DisableNotThrow::Disable }, impl{ numVertices, numTargets, numKeys }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, MorphController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController, GetNumVertices, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController, GetNumTargets, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, MorphController, GetNumKeys, int)

Rendering::MorphController::APoint Rendering::MorphController::GetVertices(int target, int vertices) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetVertices(target, vertices);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, MorphController, GetTimes, int, float)

float Rendering::MorphController::GetWeights(int key, int target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return impl->GetWeights(key, target);
}

void Rendering::MorphController::SetVertices(int target, int vertices, const APoint& point)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetVertices(target, vertices, point);
}

void Rendering::MorphController::SetTimes(int key, float times)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTimes(key, times);
}

void Rendering::MorphController::SetWeights(int key, int target, float weights)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetWeights(key, target, weights);
}

bool Rendering::MorphController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    // 键插值操作使用线性内插。为了获得更高级的插值，
    // 您需要提供一个更复杂的密钥（例如贝塞尔三次或TCB样条曲线）。

    if (ParentType::Update(applicationTime))
    {
        // 访问该顶点缓冲器来存储混合目标。
        auto visual = dynamic_cast<Visual*>(GetControllerObject());
        if (visual != nullptr)
        {
            RENDERING_ASSERTION_2(impl->GetNumVertices() == visual->GetVertexBuffer()->GetNumElements(), "顶点数不匹配\n");

            auto vba = *visual->GetVertexBuffer();

            // 查找边界键。
            auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

            const auto info = GetKeyInfo(ctrlTime);

            // 加入剩余的组分在凸状组合
            for (auto i = 1; i < impl->GetNumTargets(); ++i)
            {
                // 添加target[i]在三角形顶点。
                const auto coeff = (1.0f - info.GetNormTime()) * impl->GetWeights(info.GetFirstIndex(), i - 1) + info.GetNormTime() * impl->GetWeights(info.GetSecondIndex(), i - 1);
            }

            visual->UpdateModelSpace(VisualUpdateType::Normals);
        

            return true;
        }
    }

    return false;
}

void Rendering::MorphController::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);
}

void Rendering::MorphController::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::SetObject(object);
}

Rendering::ControllerInterfaceSharedPtr Rendering::MorphController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, MorphController, GetKeyInfo, float, Rendering::ControllerKeyInfo)

Rendering::MorphController::MorphController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::MorphController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::MorphController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::MorphController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::MorphController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::MorphController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::MorphController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::MorphController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
