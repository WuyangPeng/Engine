/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 11:16)

#include "Rendering/RenderingExport.h"

#include "Camera.h"
#include "Detail/CameraImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Camera)
CORE_TOOLS_RTTI_DEFINE(Rendering, Camera)
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Camera)
CORE_TOOLS_FACTORY_DEFINE(Rendering, Camera)
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, Camera)

Rendering::Camera::CameraSharedPtr Rendering::Camera::Create(bool isPerspective, DepthType depthType, float epsilon)
{
    return std::make_shared<ClassType>(isPerspective, depthType, epsilon);
}

Rendering::Camera::Camera(bool isPerspective, DepthType depthType, float epsilon)
    : ParentType{ isPerspective, depthType, epsilon }, impl{ epsilon }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, Camera)

void Rendering::Camera::SetPreViewMatrix(const Matrix& preViewMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetPreViewMatrix(preViewMatrix);
    ParentType::UpdateProjectionViewMatrix();
    UpdateProjectionViewMatrix();
}

Rendering::ViewVolume::Matrix Rendering::Camera::GetPreViewMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPreViewMatrix();
}

bool Rendering::Camera::PreViewIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->PreViewIsIdentity();
}

void Rendering::Camera::SetPostProjectionMatrix(const Matrix& postProjMatrix)
{
    RENDERING_CLASS_IS_VALID_9;

    impl->SetPostProjectionMatrix(postProjMatrix);
    ParentType::UpdateProjectionViewMatrix();
    UpdateProjectionViewMatrix();
}

Rendering::ViewVolume::Matrix Rendering::Camera::GetPostProjectionMatrix() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetPostProjectionMatrix();
}

bool Rendering::Camera::PostProjectionIsIdentity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->PostProjectionIsIdentity();
}

void Rendering::Camera::SetProjectionMatrix(const APoint& p00, const APoint& p10, const APoint& p11, const APoint& p01, float nearExtrude, float farExtrude)
{
    RENDERING_CLASS_IS_VALID_9;

    RENDERING_ASSERTION_0(0.0f < nearExtrude, "nearExtrude必须大于0\n");
    RENDERING_ASSERTION_0(nearExtrude < farExtrude, "farExtrude必须大于nearExtrude\n");

    /// 计算最近面的视图体积。注释后的代码行显示了q110应该是什么，但实际的算法不需要计算它。
    constexpr auto origin = Mathematics::APointF::GetOrigin();
    const auto q000 = origin + nearExtrude * (p00 - origin);
    const auto q100 = origin + nearExtrude * (p10 - origin);

#if 0

    const auto q110 = origin + nearExtrude * (p11 - origin);

#endif  // 0

    const auto q010 = origin + nearExtrude * (p01 - origin);

    // 计算最远面的视图体积。注释后的代码行显示了q101和q011应该是什么，但实际的算法不需要计算它。
    const auto q001 = origin + farExtrude * (p00 - origin);

#if 0

    const auto q101 = origin + farExtrude * (p10 - origin);
    const auto q011 = origin + farExtrude * (p01 - origin);

#endif  // 0

    const auto q111 = origin + farExtrude * (p11 - origin);

    // 计算q111的表示
    const auto u0 = q100 - q000;
    const auto u1 = q010 - q000;
    const auto u2 = q001 - q000;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const Matrix matrix{ u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Row };
    const auto inverseMatrix = matrix.Inverse(impl->GetEpsilon());
    auto point = inverseMatrix * q111;

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    const Matrix matrix{ u0, u1, u2, q000, Mathematics::MatrixMajorFlags::Column };
    const auto inverseMatrix = matrix.Inverse(impl->GetEpsilon());
    auto point = q111 * inverseMatrix;

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)

    // 计算分段线性变换的参数。
    //  y[i] = n[i]*x[i]/(d[0]*x[0] + d[1]*x[1] + d[2]*x[2] + d[3])
    const auto twoPoint0 = 2.0f * point[0];
    const auto twoPoint1 = 2.0f * point[1];
    const auto twoPoint2 = 2.0f * point[2];
    const auto d0 = +point[0] - point[1] - point[2] + 1.0f;
    const auto d1 = -point[0] + point[1] - point[2] + 1.0f;
    const auto d2 = -point[0] - point[1] + point[2] + 1.0f;
    const auto d3 = +point[0] + point[1] + point[2] - 1.0f;

    // 计算透视投影从规范化长方体到规范化立方体[-1,1]^2 x [0,1]
    const auto twoPoint2divide0 = twoPoint2 / twoPoint0;
    const auto twoPoint2divide1 = twoPoint2 / twoPoint1;

#if defined(MATHEMATICS_USE_MATRIX_VECTOR)

    Matrix project{};
    project(0, 0) = twoPoint2divide0 * (2.0f * d3 + d0);
    project(0, 1) = twoPoint2divide1 * d1;
    project(0, 2) = d2;
    project(0, 3) = -twoPoint2;

    project(1, 0) = twoPoint2divide0 * d0;
    project(1, 1) = twoPoint2divide1 * (2.0f * d3 + d1);
    project(1, 2) = d2;
    project(1, 3) = -twoPoint2;

    project(2, 0) = 0.0f;
    project(2, 1) = 0.0f;
    project(2, 2) = d3;
    project(2, 3) = 0.0f;

    project(3, 0) = -twoPoint2divide0 * d0;
    project(3, 1) = -twoPoint2divide1 * d1;
    project(3, 2) = -d2;
    project(3, 3) = twoPoint2;

#else  // !defined(MATHEMATICS_USE_MATRIX_VECTOR)

    Matrix project{};
    project(0, 0) = twoPoint2divide0 * (2.0f * d3 + d0);
    project(1, 0) = twoPoint2divide1 * d1;
    project(2, 0) = d2;
    project(3, 0) = -twoPoint2;

    project(0, 1) = twoPoint2divide0 * d0;
    project(1, 1) = twoPoint2divide1 * (2.0f * d3 + d1);
    project(2, 1) = d2;
    project(3, 1) = -twoPoint2;

    project(0, 2) = 0.0f;
    project(1, 2) = 0.0f;
    project(2, 2) = d3;
    project(3, 2) = 0.0f;

    project(0, 3) = -twoPoint2divide0 * d0;
    project(1, 3) = -twoPoint2divide1 * d1;
    project(2, 3) = -d2;
    project(3, 3) = twoPoint2;

#endif  // defined(MATHEMATICS_USE_MATRIX_VECTOR)

    // 全投影需要将挤压四边形投影视图体积映射到规范长方体，然后再将透视投影映射到规范立方体。
    ParentType::SetProjectionMatrix(project * inverseMatrix);
    UpdateProjectionViewMatrix();
}

void Rendering::Camera::UpdateProjectionViewMatrix() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    const auto matrix = GetProjectionViewMatrix();

    SetProjectionViewMatrix(impl->GetProjectionViewMatrix(matrix));
}

CoreTools::ObjectInterfaceSharedPtr Rendering::Camera::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::PickLine Rendering::Camera::GetPickLine(int viewX, int viewY, int viewWidth, int viewHigh, int x, int y) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (viewX <= x && x <= viewX + viewWidth && viewY <= y && y <= viewY + viewHigh)
    {
        APoint origin{};
        AVector direction{};

        // 获取(x,y)的[0,1]^2归一化坐标。
        const auto r = (static_cast<float>(x - viewX)) / static_cast<float>(viewWidth);
        const auto u = (static_cast<float>(y - viewY)) / static_cast<float>(viewHigh);

        // 获取[rMin,rMax]x[uMin,uMax]中的相对坐标。
        const auto rBlend = (1.0f - r) * GetRightMin() + r * GetRightMax();
        const auto uBlend = (1.0f - u) * GetUpMin() + u * GetUpMax();

        if (IsPerspective())
        {
            origin = GetPosition();
            direction = GetDirectionMin() * GetDirectionVector() + rBlend * GetRightVector() + uBlend * GetUpVector();
            direction.Normalize(impl->GetEpsilon());
        }
        else
        {
            origin = GetPosition() + rBlend * GetRightVector() + uBlend * GetUpVector();
            direction = GetDirectionVector();
        }

        return PickLine{ origin, direction, true };
    }
    else
    {
        // (x,y)在视口之外。
        return PickLine{};
    }
}
