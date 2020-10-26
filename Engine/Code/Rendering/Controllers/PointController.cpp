// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.0.3 (2019/07/23 15:33)

#include "Rendering/RenderingExport.h"

#include "PointController.h"
#include "Detail/PointControllerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "Mathematics/Algebra/MatrixDetail.h"
#include "Rendering/Renderers/RendererManager.h"
#include "Rendering/Resources/Buffer.h"
#include "Rendering/Resources/VertexBufferAccessor.h"
#include "Rendering/SceneGraph/Polypoint.h"
#include "Rendering/SceneGraph/Visual.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26455)
#include SYSTEM_WARNING_DISABLE(26456)
using std::make_shared;

CORE_TOOLS_RTTI_DEFINE(Rendering, PointController);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, PointController);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, PointController);

Rendering::PointController ::PointController()
    : ParentType{}, m_Impl{ make_shared<ImplType>() }, m_Points{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

 
Rendering::PointController ::PointController(const PointController& rhs)
    : ParentType(rhs), m_Impl{ make_shared<ImplType>(*rhs.m_Impl) }, m_Points{ dynamic_cast<Polypoint*>(GetControllerObject()) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::PointController& Rendering::PointController ::operator=(const PointController& rhs)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::operator=(rhs);
    m_Impl = make_shared<ImplType>(*rhs.m_Impl);
    m_Points = dynamic_cast<Polypoint*>(GetControllerObject());

    return *this;
}

CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, PointController)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetNumPoints, int)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointLinearSpeed, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointAngularSpeed, int, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointLinearAxis, int, const Rendering::PointController::AVector)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, PointController, GetPointAngularAxis, int, const Rendering::PointController::AVector)

void Rendering::PointController ::SetPointLinearSpeed(int index, float pointLinearSpeed)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetPointLinearSpeed(index, pointLinearSpeed);
}

void Rendering::PointController ::SetPointAngularSpeed(int index, float pointAngularSpeed)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetPointAngularSpeed(index, pointAngularSpeed);
}

void Rendering::PointController ::SetPointLinearAxis(int index, const AVector& pointLinearAxis)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetPointLinearAxis(index, pointLinearAxis);
}

void Rendering::PointController ::SetPointAngularAxis(int index, const AVector& pointAngularAxis)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    return m_Impl->SetPointAngularAxis(index, pointAngularAxis);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemLinearSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, PointController, SetSystemLinearSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemAngularSpeed, float)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V_NOEXCEPT(Rendering, PointController, SetSystemAngularSpeed, float, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemLinearAxis, const Rendering::PointController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, PointController, SetSystemLinearAxis, AVector, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, PointController, GetSystemAngularAxis, const Rendering::PointController::AVector)
IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR_NOEXCEPT(Rendering, PointController, SetSystemAngularAxis, AVector, void)

void Rendering::PointController ::Reallocate(int numPoints)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (0 < numPoints)
        m_Impl = make_shared<ImplType>(numPoints);
    else
        m_Impl = make_shared<ImplType>();
}

void Rendering::PointController ::SetObject(ControllerInterface* object)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;
    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    ParentType::SetObject(object);

    if (object != nullptr)
    {
        m_Points = dynamic_cast<Polypoint*>(object);
        Reallocate(m_Points->GetVertexBuffer()->GetNumElements());
    }
    else
    {
        m_Points = nullptr;
        Reallocate(0);
    }
}

void Rendering::PointController ::SetObjectInCopy(ControllerInterface* object)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::SetObject(object);
}

bool Rendering::PointController ::Update(double applicationTime)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (Controller::Update(applicationTime))
    {
        auto ctrlTime = boost::numeric_cast<float>(GetControlTime(applicationTime));

        UpdateSystemMotion(ctrlTime);
        UpdatePointMotion(ctrlTime);

        return true;
    }

    return false;
}

void Rendering::PointController ::UpdateSystemMotion(float ctrlTime)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (m_Points != nullptr)
    {
        const auto distance = ctrlTime * GetSystemLinearSpeed();
        auto deltaTrn = distance * GetSystemLinearAxis();
        auto localTransform = m_Points->GetLocalTransform();
        const auto translate = localTransform.GetTranslate() + deltaTrn;
        localTransform.SetTranslate(translate);

        const auto angle = ctrlTime * GetSystemAngularSpeed();
        const Mathematics::FloatMatrix deltaRot{ GetSystemAngularAxis(), angle };
        const auto rotate = deltaRot * localTransform.GetRotate();
        localTransform.SetRotate(rotate);

        m_Points->SetLocalTransform(localTransform);
    }
}

void Rendering::PointController ::UpdatePointMotion(float ctrlTime)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    if (m_Points != nullptr)
    {
        VertexBufferAccessor vba{ m_Points };

        const auto numPoints = m_Points->GetNumPoints();
        for (auto i = 0; i < numPoints; ++i)
        {
            const auto distance = ctrlTime * GetPointLinearSpeed(i);
            auto position = vba.GetPosition<Mathematics::FloatAPoint>(i);
            auto deltaTrn = distance * GetPointLinearAxis(i);
            m_Points->GetVertexBuffer()->SetPosition(vba, i, position + deltaTrn);
        }

        if (vba.HasNormal())
        {
            for (auto i = 0; i < numPoints; ++i)
            {
                const auto angle = ctrlTime * GetPointAngularSpeed(i);
                auto normal = vba.GetNormal<AVector>(i);
                normal.Normalize();
                const Mathematics::FloatMatrix deltaRot{ GetPointAngularAxis(i), angle };
                m_Points->GetVertexBuffer()->SetTriangleNormal(vba, i, deltaRot * normal);
            }
        }

        RENDERER_MANAGE_SINGLETON.UpdateAll(m_Points->GetConstVertexBuffer().get());
    }
}

Rendering::PointController ::PointController(LoadConstructor value)
    : ParentType{ value }, m_Impl{ make_shared<ImplType>() }, m_Points{ nullptr }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::PointController ::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += m_Impl->GetStreamingSize();

    return size;
}

uint64_t Rendering::PointController ::Register(const CoreTools::ObjectRegisterSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::PointController ::Save(const CoreTools::BufferTargetSharedPtr& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    m_Impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::PointController ::Link(const CoreTools::ObjectLinkSharedPtr& source)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::Link(source);
}

void Rendering::PointController ::PostLink()
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    ParentType::PostLink();

    auto object = GetControllerObject();

    RENDERING_ASSERTION_0(object == nullptr || object->IsDerived(Visual::GetCurrentRttiType()), "无效类\n");

    m_Points = dynamic_cast<Polypoint*>(object);
}

void Rendering::PointController ::Load(const CoreTools::BufferSourceSharedPtr& source)
{
    IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    m_Impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

#include STSTEM_WARNING_POP