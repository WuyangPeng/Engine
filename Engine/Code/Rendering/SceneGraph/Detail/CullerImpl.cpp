///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:13)

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

    // ����ƽ��ͷ���ֵ��
    frustum.SetFrustum(aFrustum);

    const auto directionMin2 = frustum.GetDirectionMin() * frustum.GetDirectionMin();
    const auto upMin2 = frustum.GetUpMin() * frustum.GetUpMin();
    const auto upMax2 = frustum.GetUpMax() * frustum.GetUpMax();
    const auto rightMin2 = frustum.GetRightMin() * frustum.GetRightMin();
    const auto rightMax2 = frustum.GetRightMax() * frustum.GetRightMax();

    // ��ȡ�������ϵ��
    const auto position = camera->GetPosition();
    const auto directionVector = camera->GetDirectionVector();
    const auto upVector = camera->GetUpVector();
    const auto rightVector = camera->GetRightVector();
    const auto directionDotEye = Dot(position, directionVector);

    const auto epsilon = camera->GetEpsilon();

    // ���½�ƽ��
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMin)) = Plane{ directionVector, directionDotEye + frustum.GetDirectionMin(), epsilon };

    // ����Զƽ��
    plane.at(System::EnumCastUnderlying(ViewFrustum::DirectionMax)) = Plane{ -directionVector, -(directionDotEye + frustum.GetDirectionMax()), epsilon };

    // ���µײ�ƽ��
    auto invLength = Math::InvSqrt(directionMin2 + upMin2);
    auto c0 = -frustum.GetUpMin() * invLength;
    auto c1 = +frustum.GetDirectionMin() * invLength;
    auto normal = c0 * directionVector + c1 * upVector;
    auto constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMin)) = Plane{ normal, constant, epsilon };

    // ���¶���ƽ��
    invLength = Math::InvSqrt(directionMin2 + upMax2);
    c0 = +frustum.GetUpMax() * invLength;
    c1 = -frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * upVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::UpMax)) = Plane(normal, constant, epsilon);

    // ������ƽ��
    invLength = Math::InvSqrt(directionMin2 + rightMin2);
    c0 = -frustum.GetRightMin() * invLength;
    c1 = +frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMin)) = Plane(normal, constant, epsilon);

    // ������ƽ��
    invLength = Math::InvSqrt(directionMin2 + rightMax2);
    c0 = +frustum.GetRightMax() * invLength;
    c1 = -frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position, normal);
    plane.at(System::EnumCastUnderlying(ViewFrustum::RightMax)) = Plane(normal, constant, epsilon);

    // ����ƽ������Ǽ���ġ�
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
        // �û������ƽ�����������޵ġ�
        plane.at(planeQuantity) = aPlane;
        ++planeQuantity;
    }
}

void Rendering::CullerImpl::PopPlane() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    if (System::EnumCastUnderlying(ViewFrustum::Quantity) < planeQuantity)
    {
        // ƽ��ͷ��ƽ����ܲ��Ӷ�ջ��ɾ����
        --planeQuantity;
    }
}

bool Rendering::CullerImpl::IsVisible(const BoundF& bound) noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (bound.GetRadius() <= Math::GetZeroTolerance())
    {
        // �ڵ���һ������ڵ㲻�ɼ���
        return false;
    }

    // �����ѹ���ƽ�濪ʼ,�������Լ������ƽ��
    auto index = planeQuantity - 1;
    auto mask = (1 << index);

    for (; 0 <= index; --index)
    {
        if (planeState & mask)
        {
            const auto side = bound.WhichSide(plane.at(index));

            if (side == Mathematics::NumericalValueSymbol::Negative)
            {
                // ������ƽ��ĸ��ߣ������޳���
                return false;
            }

            if (side == Mathematics::NumericalValueSymbol::Positive)
            {
                // ������ƽ������ߡ�û�б�Ҫ��ƽ��Ƚ��Ӷ���,���Խ�����Ϊ�ǻ��
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

    // �����Զ������һ�����ʱ����������ignoreNearPlaneӦ������Ϊ��true����
    // ��ͱ����˵������ͼ�еĽ�����(��+��/��/��/��),�����۾�������ƽ��֮������������
    // �����������,����ϣ�����ϵͳ��������ڡ�
    // �������ͨ��������������ƶ�ͨ����ڴӵ�ǰ�������ڵ�����

    // �����ѹ���ƽ�濪ʼ,�������Լ������ƽ��
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
                // ƽ����Ķ���β�����ȫ��
                which = j;
                break;
            }
        }

        if (which == numVertices)
        {
            // �������ȫ��ƽ����ġ�
            return false;
        }
    }

    return true;
}

Mathematics::NumericalValueSymbol Rendering::CullerImpl::WhichSide(const Plane& aPlane) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // ƽ����N * (X - C) = 0,����*��ʾ�����
    // �з��ž���������λ��E��ƽ����N * (E - C)��
    auto nDotEMinusC = aPlane.DistanceTo(camera->GetPosition());

    const auto normal = aPlane.GetNormal();
    const auto nDotDirection = Dot(normal, camera->GetDirectionVector());
    const auto nDotUp = Dot(normal, camera->GetUpVector());
    const auto nDotRight = Dot(normal, camera->GetRightVector());
    const auto directionRatio = frustum.GetDirectionMax() / frustum.GetDirectionMin();

    auto positive = 0;
    auto negative = 0;

    // ����ƽ�涥�㡣
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

    // ���Զƽ�涥�㡣 (s = dmax / dmin)
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
            // ƽ��ͷ��λ��ƽ�档
            return Mathematics::NumericalValueSymbol::Zero;
        }

        // ƽ��ͷ����ȫ�����档
        return Mathematics::NumericalValueSymbol::Positive;
    }

    // ƽ��ͷ����ȫ�ڸ��档
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
