///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 16:03)

#include "Rendering/RenderingExport.h"

#include "KeyframeController.h"
#include "Detail/KeyframeControllerImpl.h"
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

using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, KeyframeController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, KeyframeController);
CORE_TOOLS_FACTORY_DEFINE(Rendering, KeyframeController);

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, KeyframeController)

Rendering::KeyframeController::KeyframeController(int numCommonTimes, int numTranslations, int numRotations, int numScales, const TransformF& localTransform)
    : ParentType{ localTransform },
      impl{ numCommonTimes, numTranslations, numRotations, numScales }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, KeyframeController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController, GetNumCommonTimes, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetCommonTimes, int, float)

void Rendering::KeyframeController::SetCommonTimes(int index, float commonTimes)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetCommonTimes(index, commonTimes);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController, GetNumTranslations, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetTranslationTimes, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetTranslations, int, Rendering::KeyframeController::APoint)

void Rendering::KeyframeController::SetTranslationTimes(int index, float translationTimes)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTranslationTimes(index, translationTimes);
}

void Rendering::KeyframeController::SetTranslations(int index, const APoint& translations)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetTranslations(index, translations);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController, GetNumRotations, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetRotationTimes, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetRotations, int, Rendering::KeyframeController::AQuaternion)

void Rendering::KeyframeController::SetRotationTimes(int index, float rotationTimes)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRotationTimes(index, rotationTimes);
}

void Rendering::KeyframeController::SetRotations(int index, const AQuaternion& rotations)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetRotations(index, rotations);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, KeyframeController, GetNumScales, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetScaleTimes, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetScales, int, float)

void Rendering::KeyframeController::SetScaleTimes(int index, float scaleTimes)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetScaleTimes(index, scaleTimes);
}

void Rendering::KeyframeController::SetScales(int index, float scales)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetScales(index, scales);
}

void Rendering::KeyframeController::SetObject(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Spatial::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);
}

void Rendering::KeyframeController::SetObjectInCopy(ControllerInterface* object)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::SetObject(object);
}

Rendering::ControllerInterfaceSharedPtr Rendering::KeyframeController::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, KeyframeController, GetTranslate, ControllerKeyInfo, Rendering::KeyframeController::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, KeyframeController, GetRotate, ControllerKeyInfo, Rendering::KeyframeController::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, KeyframeController, GetScale, ControllerKeyInfo, float)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetTranslateKeyInfo, float, Rendering::ControllerKeyInfo)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetRotateKeyInfo, float, Rendering::ControllerKeyInfo)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetScaleKeyInfo, float, Rendering::ControllerKeyInfo)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, KeyframeController, GetCommonKeyInfo, float, Rendering::ControllerKeyInfo)

bool Rendering::KeyframeController::Update(double applicationTime)
{
    RENDERING_CLASS_IS_VALID_1;

    if (ParentType::Update(applicationTime))
    {
        auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        // 这里的逻辑检查同样时间的数组，以减少调用GetKeyInfo的次数。
        if (0 < GetNumCommonTimes())
        {
            const auto controllerKeyInfo = GetCommonKeyInfo(ctrlTime);

            if (0 < GetNumTranslations())
            {
                const auto translate = GetTranslate(controllerKeyInfo);

                SetTranslate(translate);
            }

            if (0 < GetNumRotations())
            {
                const auto rotate = GetRotate(controllerKeyInfo);
                SetRotate(rotate);
            }

            if (0 < GetNumScales())
            {
                const auto scale = GetScale(controllerKeyInfo);
                SetUniformScale(scale);
            }
        }
        else
        {
            if (0 < GetNumTranslations())
            {
                const auto controllerKeyInfo = GetTranslateKeyInfo(ctrlTime);
                const auto translate = GetTranslate(controllerKeyInfo);

                SetTranslate(translate);
            }

            if (0 < GetNumRotations())
            {
                const auto controllerKeyInfo = GetRotateKeyInfo(ctrlTime);
                const auto rotate = GetRotate(controllerKeyInfo);
                SetRotate(rotate);
            }

            if (0 < GetNumScales())
            {
                const auto controllerKeyInfo = GetScaleKeyInfo(ctrlTime);
                const auto scale = GetScale(controllerKeyInfo);
                SetUniformScale(scale);
            }
        }
        auto spatial = dynamic_cast<Spatial*>(GetControllerObject());
        if (spatial != nullptr)
        {
            spatial->SetLocalTransform(GetTransform());
        }

        return true;
    }

    return false;
}

Rendering::KeyframeController::KeyframeController(LoadConstructor value)
    : ParentType{ value }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::KeyframeController::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::KeyframeController::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::KeyframeController::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::KeyframeController::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::KeyframeController::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::KeyframeController::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::KeyframeController::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
