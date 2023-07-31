///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:05)

#include "Rendering/RenderingExport.h"

#include "BlendTransformController.h"
#include "Detail/BlendTransformControllerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/SceneGraph/Spatial.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, BlendTransformController)

CORE_TOOLS_RTTI_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BlendTransformController);
CORE_TOOLS_DEFAULT_NAMES_USE_IMPL_DEFINE(Rendering, BlendTransformController);

Rendering::BlendTransformController::BlendTransformController(const TransformControllerSharedPtr& firstController,
                                                              const TransformControllerSharedPtr& secondController,
                                                              bool rotationScaleMatrices,
                                                              bool geometricRotation,
                                                              bool geometricScale)
    : ParentType{ TransformF{} }, impl{ firstController, secondController, rotationScaleMatrices, geometricRotation, geometricScale }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, BlendTransformController)

Rendering::ControllerInterfaceSharedPtr Rendering::BlendTransformController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::BlendTransformController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

Rendering::BlendTransformController::BlendTransformController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::BlendTransformController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::BlendTransformController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    const auto registerID = ParentType::Register(target);
    if (registerID != 0)
    {
        impl->Register(target);
    }

    return registerID;
}

void Rendering::BlendTransformController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::BlendTransformController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);

    impl->Link(source);
}

void Rendering::BlendTransformController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::BlendTransformController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetFirstController, Rendering::ConstTransformControllerSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetSecondController, Rendering::ConstTransformControllerSharedPtr)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, IsRotationScaleMatrices, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, BlendTransformController, SetWeight, float, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, GetWeight, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, IsGeometricRotation, bool)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, BlendTransformController, IsGeometricScale, bool)

void Rendering::BlendTransformController::SetControllerObject(const ControllerInterfaceSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::GetCurrentRttiType()), "无效类\n");

    ParentType::SetControllerObject(object);
    impl->SetObject(object);
}

bool Rendering::BlendTransformController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (ParentType::Update(applicationTime))
    {
        impl->Update(applicationTime);

        const auto blendTranslate = impl->GetBlendTranslate();

        SetTranslate(blendTranslate);

        if (impl->IsRotationScaleMatrices())
        {
            const auto blendQuaternion = impl->GetBlendQuaternion();

            SetRotate(blendQuaternion);

            const auto blendScale = impl->GetBlendScale();

            SetScale(blendScale);
        }
        else
        {
            // 算术混合矩阵。
            const auto blendMatrix = impl->GetMatrix();

            SetMatrix(blendMatrix);
        }

        auto spatial = boost::polymorphic_pointer_cast<Spatial>(GetControllerObject());

        if (spatial != nullptr)
        {
            spatial->SetLocalTransform(GetTransform());

            return true;
        }
    }

    return false;
}
