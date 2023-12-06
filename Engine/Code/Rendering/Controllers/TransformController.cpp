///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/24 11:26)

#include "Rendering/RenderingExport.h"

#include "TransformController.h"
#include "Detail/TransformControllerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
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
#include "Rendering/SceneGraph/Spatial.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TransformController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TransformController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TransformController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TransformController)

Rendering::TransformController::TransformController(const Mathematics::TransformF& localTransform)
    : ParentType{ "TransformController" }, impl{ localTransform }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TransformController)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, TransformController, SetTransform, Mathematics::TransformF, void)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, TransformController, GetTransform, Mathematics::TransformF)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, TransformController, SetTranslate, APoint, void)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, TransformController, SetRotate, Matrix, void)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, TransformController, SetMatrix, Matrix, void)

void Rendering::TransformController::SetUniformScale(float scale)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetUniformScale(scale);
}

void Rendering::TransformController::SetScale(const APoint& scale)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetScale(scale);
}

void Rendering::TransformController::SetController(const ControllerSharedPtr& object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::GetCurrentRttiType()), "无效类\n");

    ParentType::SetController(object);
}

bool Rendering::TransformController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (ParentType::Update(applicationTime))
    {
        if (const auto spatial = boost::polymorphic_pointer_cast<Spatial>(GetController());
            spatial != nullptr)
        {
            spatial->SetLocalTransform(impl->GetTransform());
            return true;
        }
    }

    return false;
}

Rendering::ControllerInterfaceSharedPtr Rendering::TransformController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

Rendering::TransformController::TransformController(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ Mathematics::TransformF{} }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::TransformController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::TransformController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TransformController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TransformController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TransformController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TransformController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TransformController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
