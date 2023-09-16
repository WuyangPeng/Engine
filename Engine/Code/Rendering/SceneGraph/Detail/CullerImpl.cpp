///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "CullerImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/PlaneDetail.h"

Rendering::CullerImpl::CullerImpl(const ConstCameraSharedPtr& camera)
    : camera{ camera },
      frustum{ false },
      planeQuantity{ System::EnumCastUnderlying(ViewFrustum::Quantity) },
      plane{},
      planeState{ 0 },
      visibleSet{ VisibleSet::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::CullerImpl::IsValid() const noexcept
{
    if (0 < planeQuantity && camera != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::CullerImpl::SetCamera(const ConstCameraSharedPtr& aCamera) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    camera = aCamera;
}

Rendering::ConstCameraSharedPtr Rendering::CullerImpl::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return camera;
}

void Rendering::CullerImpl::SetFrustum(const float* aFrustum)
{
    RENDERING_CLASS_IS_VALID_1;

    // 复制平截头体的值。
    frustum.SetFrustum(aFrustum);

    const auto directionMin2 = frustum.GetDirectionMin() * frustum.GetDirectionMin();
    const auto upMin2 = frustum.GetUpMin() * frustum.GetUpMin();
    const auto upMax2 = frustum.GetUpMax() * frustum.GetUpMax();
    const auto rightMin2 = frustum.GetRightMin() * frustum.GetRightMin();
    const auto rightMax2 = frustum.GetRightMax() * frustum.GetRightMax();

    // 获取相机坐标系。
    const auto position = camera->GetPosition();
    const auto directionVector = camera->GetDirectionVector();
    const auto upVector = camera->GetUpVector();
    const auto rightVector = camera->GetRightVector();
    const auto directionDotEye = Dot(position, directionVector);

    const auto epsilon = camera->GetEpsilon();

    // 更新近平面
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin)) = Plane{ directionVector, directionDotEye + frustum.GetDirectionMin(), epsilon };

    // 更新远平面
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax)) = Plane{ -directionVector, -(directionDotEye + frustum.GetDirectionMax()), epsilon };

    // 更新底部平面
    auto invLength = Math::InvSqrt(directionMin2 + upMin2);
    auto c0 = -frustum.GetUpMin() * invLength;
    auto c1 = +frustum.GetDirectionMin() * invLength;
    auto normal = c0 * directionVector + c1 * upVector;
    auto constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = Plane{ normal, constant, epsilon };

    // 更新顶部平面
    invLength = Math::InvSqrt(directionMin2 + upMax2);
    c0 = +frustum.GetUpMax() * invLength;
    c1 = -frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * upVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = Plane(normal, constant, epsilon);

    // 更新左平面
    invLength = Math::InvSqrt(directionMin2 + rightMin2);
    c0 = -frustum.GetRightMin() * invLength;
    c1 = +frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = Plane(normal, constant, epsilon);

    // 更新右平面
    invLength = Math::InvSqrt(directionMin2 + rightMax2);
    c0 = +frustum.GetRightMax() * invLength;
    c1 = -frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = Plane(normal, constant, epsilon);

    // 所有平面最初是激活的。
    planeState = 0xFFFFFFFF;
}

const float* Rendering::CullerImpl::GetFrustum() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return frustum.GetFrustum();
}

void Rendering::CullerImpl::Insert(const VisualSharedPtr& visible)
{
    RENDERING_CLASS_IS_VALID_1;

    visibleSet.Insert(visible);
}

int Rendering::CullerImpl::GetPlaneQuantity() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return planeQuantity;
}

const Rendering::CullerImpl::Plane* Rendering::CullerImpl::GetPlanes() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return plane.data();
}

void Rendering::CullerImpl::SetPlaneState(int aPlaneState) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    planeState = aPlaneState;
}

int Rendering::CullerImpl::GetPlaneState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return planeState;
}

void Rendering::CullerImpl::PushPlane(const Plane& aPlane) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (planeQuantity < MaxPlaneQuantity)
    {
        // 用户定义的平面数量是有限的。
        plane.at(planeQuantity) = aPlane;
        ++planeQuantity;
    }
}

void Rendering::CullerImpl::PopPlane() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (System::EnumCastUnderlying(ViewFrustum::Quantity) < planeQuantity)
    {
        // 平截头体平面可能不从堆栈中删除。
        --planeQuantity;
    }
}

bool Rendering::CullerImpl::IsVisible(const BoundF& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (bound.GetRadius() <= Math::GetZeroTolerance())
    {
        // 节点是一个虚拟节点不可见。
        return false;
    }

    // 从最后压入的平面开始,这可能是约束最大的平面
    auto index = planeQuantity - 1;
    auto mask = (1 << index);

    for (; 0 <= index; --index)
    {
        if (planeState & mask)
        {
            const auto side = bound.WhichSide(plane.at(index));

            if (side == Mathematics::NumericalValueSymbol::Negative)
            {
                // 对象在平面的负边，所以剔除。
                return false;
            }

            if (side == Mathematics::NumericalValueSymbol::Positive)
            {
                // 对象在平面的正边。没有必要对平面比较子对象,所以将其标记为非活动。
                planeState &= ~mask;
            }
        }

        mask >>= 1;
    }

    return true;
}

bool Rendering::CullerImpl::IsVisible(int numVertices, const APoint* vertices, bool ignoreNearPlane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (vertices == nullptr)
    {
        return false;
    }

    // 当测试多边形是一个入口时，布尔变量ignoreNearPlane应该设置为“true”。
    // 这就避免了当入口视图中的金字塔(眼+左/右/上/下),但在眼睛附近和平面之间的这种情况。
    // 在这种情况下,您不希望入口系统来过滤入口。
    // 这种情况通常发生在摄像机移动通过入口从当前区域到相邻的区域。

    // 从最后压入的平面开始,这可能是约束最大的平面
    for (auto index = planeQuantity - 1; 0 <= index; --index)
    {
        const auto& aPlane = plane.at(index);
        if (ignoreNearPlane && index == System::EnumCastUnderlying(ViewFrustum::DirectionMin))
        {
            continue;
        }

        auto which = numVertices;
        for (auto j = 0; j < numVertices; ++j)
        {
#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)

            const auto side = aPlane.WhichSide(vertices[j]);

#include SYSTEM_WARNING_POP

            if (side != Mathematics::NumericalValueSymbol::Negative)
            {
                // 平面外的多边形并不完全。
                which = j;
                break;
            }
        }

        if (which == numVertices)
        {
            // 多边形完全在平面外的。
            return false;
        }
    }

    return true;
}

Mathematics::NumericalValueSymbol Rendering::CullerImpl::WhichSide(const Plane& aPlane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // 平面是N * (X - C) = 0,这里*表示点积。
    // 有符号距离从摄像机位置E到平面是N * (E - C)。
    auto nDotEMinusC = aPlane.DistanceTo(camera->GetPosition());

    const auto normal = aPlane.GetNormal();
    const auto nDotDirection = Dot(normal, camera->GetDirectionVector());
    const auto nDotUp = Dot(normal, camera->GetUpVector());
    const auto nDotRight = Dot(normal, camera->GetRightVector());
    const auto directionRatio = frustum.GetDirectionMax() / frustum.GetDirectionMin();

    auto positive = 0;
    auto negative = 0;

    // 检查近平面顶点。
    const auto pDirectionMin = frustum.GetDirectionMin() * nDotDirection;
    const auto nearUpMin = frustum.GetUpMin() * nDotUp;
    const auto nearUpMax = frustum.GetUpMax() * nDotUp;
    const auto nearRightMin = frustum.GetRightMin() * nDotRight;
    const auto nearRightMax = frustum.GetRightMax() * nDotRight;

    // V = E + dmin * D + umin * U + rmin * R
    // N * (V - C) = N * (E - C) + dmin * (N * D) + umin * (N * U) + rmin * (N * R)
    auto signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmin * D + umin * U + rmax * R
    // N * (V - C) = N * (E - C) + dmin * (N * D) + umin * (N * U) + rmax * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmin * D + umax * U + rmin * R
    // N * (V - C) = N * (E - C) + dmin * (N * D) + umax * (N * U) + rmin * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmin * D + umax * U + rmax * R
    // N * (V - C) = N * (E - C) + dmin * (N * D) + umax * (N * U) + rmax * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // 检查远平面顶点。 (s = dmax / dmin)
    const auto pDirectionMax = frustum.GetDirectionMax() * nDotDirection;
    const auto farUpMin = directionRatio * nearUpMin;
    const auto farUpMax = directionRatio * nearUpMax;
    const auto farRightMin = directionRatio * nearRightMin;
    const auto farRightMax = directionRatio * nearRightMax;

    // V = E + dmax * D + umin * U + rmin * R
    // N * (V - C) = N * (E - C) + dmax * (N * D) + s * umin * (N * U) + s * rmin * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmax * D + umin * U + rmax * R
    // N * (V - C) = N * (E - C) + dmax * (N * D) + s * umin * (N * U) + s * rmax * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmax * D + umax * U + rmin * R
    // N * (V - C) = N * (E - C) + dmax * (N * D) + s * umax * (N * U) + s * rmin * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMax + farRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dmax * D + umax * U + rmax * R
    // N * (V - C) = N * (E - C) + dmax * (N * D) + s * umax * (N * U) + s * rmax * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMax + farRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    if (0 < positive)
    {
        if (0 < negative)
        {
            // 平截头体位于平面。
            return Mathematics::NumericalValueSymbol::Zero;
        }

        // 平截头体完全在正面。
        return Mathematics::NumericalValueSymbol::Positive;
    }

    // 平截头体完全在负面。
    return Mathematics::NumericalValueSymbol::Negative;
}

void Rendering::CullerImpl::Clear() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    visibleSet.Clear();
}

int Rendering::CullerImpl::GetNumVisible() const
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.GetNumVisible();
}

Rendering::ConstVisualSharedPtr Rendering::CullerImpl::GetVisible(int index) const
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.GetVisible(index);
}

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl::begin() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.begin();
}

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl::end() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.end();
}
