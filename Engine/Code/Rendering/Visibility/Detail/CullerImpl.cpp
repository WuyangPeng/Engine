/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 16:02)

#include "Rendering/RenderingExport.h"

#include "CullerImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Mathematics/Algebra/BoundingSphereDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"

Rendering::CullerImpl::CullerImpl(ConstCameraSharedPtr camera)
    : camera{ std::move(camera) },
      frustum{ false, Mathematics::MathF::GetZeroTolerance() },
      planeQuantity{ System::EnumCastUnderlying(ViewFrustum::Quantity) },
      plane{},
      planeState{ 0 },
      visibleSet{ VisibleSet::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CullerImpl::CullerImpl(const CullerImpl& rhs)
    : camera{ rhs.camera->Clone() },
      frustum{ rhs.frustum },
      planeQuantity{ rhs.planeQuantity },
      plane{ rhs.plane },
      planeState{ rhs.planeState },
      visibleSet{ rhs.visibleSet }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CullerImpl& Rendering::CullerImpl::operator=(const CullerImpl& rhs)
{
    RENDERING_CLASS_IS_VALID_1;

    if (this == &rhs)
    {
        return *this;
    }

    camera = rhs.camera->Clone();
    frustum = rhs.frustum;
    planeQuantity = rhs.planeQuantity;
    plane = rhs.plane;
    planeState = rhs.planeState;
    visibleSet = rhs.visibleSet;

    return *this;
}

Rendering::CullerImpl::CullerImpl(CullerImpl&& rhs) noexcept
    : camera{ std::move(rhs.camera) },
      frustum{ rhs.frustum },
      planeQuantity{ rhs.planeQuantity },
      plane{ rhs.plane },
      planeState{ rhs.planeState },
      visibleSet{ std::move(rhs.visibleSet) }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CullerImpl& Rendering::CullerImpl::operator=(CullerImpl&& rhs) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    camera = std::move(rhs.camera);
    frustum = rhs.frustum;
    planeQuantity = rhs.planeQuantity;
    plane = rhs.plane;
    planeState = rhs.planeState;
    visibleSet = std::move(rhs.visibleSet);

    return *this;
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

void Rendering::CullerImpl::SetFrustum(const Container& aFrustum)
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

    constexpr auto epsilon = Mathematics::MathF::GetZeroTolerance();

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

Rendering::CullerImpl::Container Rendering::CullerImpl::GetFrustum() const noexcept
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

Rendering::CullerImpl::Plane Rendering::CullerImpl::GetPlane(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return plane.at(index);
}

void Rendering::CullerImpl::SetPlaneState(uint32_t aPlaneState) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    planeState = aPlaneState;
}

uint32_t Rendering::CullerImpl::GetPlaneState() const noexcept
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

bool Rendering::CullerImpl::IsVisible(const BoundingSphere& bound) noexcept
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

Mathematics::NumericalValueSymbol Rendering::CullerImpl::WhichSide(const Plane& aPlane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    /// 平面是N * (X - C) = 0,这里*表示点积。
    /// 有符号距离从摄像机位置E到平面是N * (E - C)。
    const auto nDotEMinusC = aPlane.DistanceTo(camera->GetPosition());

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

    // V = E + dMin * D + uMin * U + rMin * R
    // N * (V - C) = N * (E - C) + dMin * (N * D) + uMin * (N * U) + rMin * (N * R)
    auto signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMin * D + uMin * U + rMax * R
    // N * (V - C) = N * (E - C) + dMin * (N * D) + uMin * (N * U) + rMax * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMin + nearRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMin * D + uMax * U + rMin * R
    // N * (V - C) = N * (E - C) + dMin * (N * D) + uMax * (N * U) + rMin * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMin * D + uMax * U + rMax * R
    // N * (V - C) = N * (E - C) + dMin * (N * D) + uMax * (N * U) + rMax * (N * R)
    signDistance = nDotEMinusC + pDirectionMin + nearUpMax + nearRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // 检查远平面顶点。 (s = dMax / dMin)
    const auto pDirectionMax = frustum.GetDirectionMax() * nDotDirection;
    const auto farUpMin = directionRatio * nearUpMin;
    const auto farUpMax = directionRatio * nearUpMax;
    const auto farRightMin = directionRatio * nearRightMin;
    const auto farRightMax = directionRatio * nearRightMax;

    // V = E + dMax * D + uMin * U + rMin * R
    // N * (V - C) = N * (E - C) + dMax * (N * D) + s * uMin * (N * U) + s * rMin * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMax * D + uMin * U + rMax * R
    // N * (V - C) = N * (E - C) + dMax * (N * D) + s * uMin * (N * U) + s * rMax * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMin + farRightMax;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMax * D + uMax * U + rMin * R
    // N * (V - C) = N * (E - C) + dMax * (N * D) + s * uMax * (N * U) + s * rMin * (N * R)
    signDistance = nDotEMinusC + pDirectionMax + farUpMax + farRightMin;
    if (0.0f < signDistance)
    {
        ++positive;
    }
    else if (signDistance < 0.0f)
    {
        ++negative;
    }

    // V = E + dMax * D + uMax * U + rMax * R
    // N * (V - C) = N * (E - C) + dMax * (N * D) + s * uMax * (N * U) + s * rMax * (N * R)
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
            return NumericalValueSymbol::Zero;
        }

        // 平截头体完全在正面。
        return NumericalValueSymbol::Positive;
    }

    // 平截头体完全在负面。
    return NumericalValueSymbol::Negative;
}

void Rendering::CullerImpl::Clear()
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

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl::begin()
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.begin();
}

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl::end()
{
    RENDERING_CLASS_IS_VALID_1;

    return visibleSet.end();
}

void Rendering::CullerImpl::PushViewFrustumPlanes(const Camera& aCamera)
{
    RENDERING_CLASS_IS_VALID_1;

    const auto dMax = aCamera.GetDirectionMax();
    const auto dMin = aCamera.GetDirectionMin();
    const auto dMin2 = dMin * dMin;
    const auto rMax = aCamera.GetRightMax();
    const auto rMax2 = rMax * rMax;
    const auto rMin = aCamera.GetRightMin();
    const auto rMin2 = rMin * rMin;
    const auto uMax = aCamera.GetUpMax();
    const auto uMax2 = uMax * uMax;
    const auto uMin = aCamera.GetUpMin();
    const auto uMin2 = uMin * uMin;

    const auto position = aCamera.GetPosition();
    const auto direction = aCamera.GetDirectionVector();
    const auto up = aCamera.GetUpVector();
    const auto right = aCamera.GetRightVector();
    const auto dirDotEye = Dot(position, direction);

    auto constant = -(dirDotEye + dMin);
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin)) = Plane{ direction, constant };

    constant = dirDotEye + dMax;
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax)) = Plane{ -direction, constant };

    auto invLength = 1.0f / std::sqrt(dMin2 + uMin2);
    auto a0 = -uMin * invLength;
    auto a1 = +dMin * invLength;
    auto normal = a0 * direction + a1 * up;
    constant = -Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = Plane{ normal, constant };

    invLength = 1.0f / std::sqrt(dMin2 + uMax2);
    a0 = +uMax * invLength;
    a1 = -dMin * invLength;
    normal = a0 * direction + a1 * up;
    constant = -Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = Plane{ normal, constant };

    invLength = 1.0f / std::sqrt(dMin2 + rMin2);
    a0 = -rMin * invLength;
    a1 = +dMin * invLength;
    normal = a0 * direction + a1 * right;
    constant = -Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = Plane{ normal, constant };

    invLength = 1.0f / std::sqrt(dMin2 + rMax2);
    a0 = +rMax * invLength;
    a1 = -dMin * invLength;
    normal = a0 * direction + a1 * right;
    constant = -Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = Plane{ normal, constant };

    planeState = 0xFFFFFFFFu;
}
