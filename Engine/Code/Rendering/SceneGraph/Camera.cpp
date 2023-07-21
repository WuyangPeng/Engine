///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:16)

#include "Rendering/RenderingExport.h"

#include "Camera.h"
#include "Detail/CameraImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/AxesAlignBoundingBox2Detail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Camera)

CORE_TOOLS_RTTI_DEFINE(Rendering, Camera);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Camera);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Camera);

Rendering::Camera::Camera(bool isPerspective, MAYBE_UNUSED bool isDepthRangeZeroOne, float epsilon)
    : ParentType{ "Camera" }, impl{ isPerspective, epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Camera)

void Rendering::Camera::SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFrame(position, directionVector, upVector, rightVector);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Camera, SetPosition, APoint, void)

void Rendering::Camera::SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetAxes(directionVector, upVector, rightVector);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetEpsilon, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetPosition, Rendering::Camera::APoint)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDirectionVector, Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetUpVector, Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetRightVector, Rendering::Camera::AVector)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetViewMatrix, Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, IsPerspective, bool)

void Rendering::Camera::SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFrustum(directionMin, directionMax, upMin, upMax, rightMin, rightMax);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Camera, SetFrustum, const float*, void)

void Rendering::Camera::SetFrustum(float upFovDegrees, float aspectRatio, float directionMin, float directionMax)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetFrustum(upFovDegrees, aspectRatio, directionMin, directionMax);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetFrustum, const float*)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetFrustumData, Rendering::CameraFrustumData)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDirectionMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDirectionMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetUpMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetUpMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetRightMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetRightMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetProjectionMatrix, Rendering::Camera::Matrix)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Camera, SetProjectionMatrix, Matrix, void)

void Rendering::Camera::SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->SetProjectionMatrix(p00, p10, p11, p01, nearExtrude, farExtrude);
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetDepthType, Rendering::DepthType)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetProjectionViewMatrix, Rendering::Camera::Matrix)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Camera, SetPreViewMatrix, Matrix, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetPreViewMatrix, Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, PreViewIsIdentity, bool)

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_CR(Rendering, Camera, SetPostProjectionMatrix, Matrix, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, GetPostProjectionMatrix, Rendering::Camera::Matrix)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, Camera, PostProjectionIsIdentity, bool)

Rendering::Camera::AxesAlignBoundingBox2D Rendering::Camera::ComputeBoundingAABB(int numVertices, const char* vertices, int stride, const Matrix& worldMatrix) const
{
    RENDERING_CLASS_IS_VALID_1;

    return impl->ComputeBoundingAABB(numVertices, vertices, stride, worldMatrix);
}

Rendering::Camera::Camera(LoadConstructor value)
    : ParentType{ value }, impl{ Math::GetZeroTolerance() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int Rendering::Camera::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += impl->GetStreamingSize();

    return size;
}

int64_t Rendering::Camera::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::Camera::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    impl->Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::Camera::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::Camera::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::Camera::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    impl->Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

IMPL_NON_CONST_MEMBER_FUNCTION_DEFINE_1_V(Rendering, Camera, SetDepthType, DepthType, void)

CoreTools::ObjectInterfaceSharedPtr Rendering::Camera::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}
