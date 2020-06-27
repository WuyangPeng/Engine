// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 16:00)

#include "Rendering/RenderingExport.h"

#include "CullerImpl.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "CoreTools/MemoryTools/ThirdSubclassSmartPointerDetail.h"
#include "CoreTools/MemoryTools/ConstThirdSubclassSmartPointerDetail.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::CullerImpl
    ::CullerImpl (const ConstCameraSmartPointer& camera)
	:m_Camera{ camera }, m_Frustum{ false }, m_PlaneQuantity{ System::EnumCastUnderlying(ViewFrustum::Quantity) }, m_PlaneState{ 0 }, m_VisibleSet{}
{
    // ���ݳ�Աm_Frustum, m_Plane,�� m_PlaneState��δ��ʼ���ġ�
    // ���ǳ�ʼ���ڵ���ComputeVisibleSet
    
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::CullerImpl
    ::~CullerImpl ()
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Rendering::CullerImpl
    ::IsValid() const noexcept
{
	if (0 < m_PlaneQuantity && !m_Camera.IsNullPtr())
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

void Rendering::CullerImpl
   ::SetCamera(const ConstCameraSmartPointer& camera)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_Camera = camera;
}

Rendering::ConstCameraSmartPointer Rendering::CullerImpl
    ::GetCamera () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Camera;
}

void Rendering::CullerImpl
    ::SetFrustum (const float* frustum)
{
    RENDERING_CLASS_IS_VALID_1;
    
    // ����ƽ��ͷ���ֵ��
    m_Frustum.SetFrustum(frustum);
    
    auto directionMin2 = m_Frustum.GetDirectionMin() * m_Frustum.GetDirectionMin();
	auto upMin2 = m_Frustum.GetUpMin() * m_Frustum.GetUpMin();
	auto upMax2 = m_Frustum.GetUpMax() * m_Frustum.GetUpMax();
	auto rightMin2 = m_Frustum.GetRightMin() * m_Frustum.GetRightMin();
	auto rightMax2 = m_Frustum.GetRightMax() * m_Frustum.GetRightMax();
    
    // ��ȡ�������ϵ��
	auto position = m_Camera->GetPosition();
	auto directionVector = m_Camera->GetDirectionVector();
	auto upVector = m_Camera->GetUpVector();
	auto rightVector = m_Camera->GetRightVector();
	auto directionDotEye = Dot(position,directionVector);

	auto epsilon = m_Camera->GetEpsilon();
    
    // ���½�ƽ��
	m_Plane[System::EnumCastUnderlying(ViewFrustum::DirectionMin)] = Plane{ directionVector,directionDotEye + m_Frustum.GetDirectionMin(),epsilon };
    
    // ����Զƽ��
	m_Plane[System::EnumCastUnderlying(ViewFrustum::DirectionMax)] = Plane{ -directionVector,-(directionDotEye + m_Frustum.GetDirectionMax()),epsilon };
    
    // ���µײ�ƽ��
	auto invLength = Math::InvSqrt(directionMin2 + upMin2);
	auto c0 = -m_Frustum.GetUpMin() * invLength;
	auto c1 = +m_Frustum.GetDirectionMin() * invLength;
	auto normal = c0 * directionVector + c1 * upVector;
	auto constant = Dot(position,normal);
	m_Plane[System::EnumCastUnderlying(ViewFrustum::UpMin)] = Plane{ normal,constant,epsilon };
    
    // ���¶���ƽ��
    invLength = Math::InvSqrt(directionMin2 + upMax2);
    c0 = +m_Frustum.GetUpMax() * invLength;
    c1 = -m_Frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * upVector;
    constant = Dot(position,normal);
    m_Plane[System::EnumCastUnderlying(ViewFrustum::UpMax)] = Plane(normal,constant,epsilon);
    
    // ������ƽ��
    invLength = Math::InvSqrt(directionMin2 + rightMin2);
    c0 = -m_Frustum.GetRightMin() * invLength;
    c1 = +m_Frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position,normal);
    m_Plane[System::EnumCastUnderlying(ViewFrustum::RightMin)] = Plane(normal,constant,epsilon);
    
    // ������ƽ��
    invLength = Math::InvSqrt(directionMin2 + rightMax2);
    c0 = +m_Frustum.GetRightMax() * invLength;
    c1 = -m_Frustum.GetDirectionMin() * invLength;
    normal = c0 * directionVector + c1 * rightVector;
    constant = Dot(position,normal);
    m_Plane[System::EnumCastUnderlying(ViewFrustum::RightMax)] = Plane(normal,constant,epsilon);
    
    // ����ƽ������Ǽ���ġ�
    m_PlaneState = 0xFFFFFFFF;
}

const float* Rendering::CullerImpl
    ::GetFrustum () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Frustum.GetFrustum ();
} 

void Rendering::CullerImpl
    ::Insert(const VisualSmartPointer& visible)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_VisibleSet.Insert(visible);
}

int Rendering::CullerImpl
    ::GetPlaneQuantity () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_PlaneQuantity;
}

const Rendering::CullerImpl::Plane* Rendering::CullerImpl
    ::GetPlanes () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_Plane;
}

void Rendering::CullerImpl
    ::SetPlaneState (unsigned int planeState)
{
    RENDERING_CLASS_IS_VALID_1;
    
    m_PlaneState = planeState;
}

unsigned int Rendering::CullerImpl
    ::GetPlaneState () const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    return m_PlaneState;
}

void Rendering::CullerImpl
    ::PushPlane (const Plane& plane)
{
    RENDERING_CLASS_IS_VALID_1;
    
    if (m_PlaneQuantity < MaxPlaneQuantity)
    {
        // �û������ƽ�����������޵ġ�
        m_Plane[m_PlaneQuantity] = plane;
        ++m_PlaneQuantity;
    }
}

void Rendering::CullerImpl
    ::PopPlane ()
{
    RENDERING_CLASS_IS_VALID_1;
    
    if (System::EnumCastUnderlying(ViewFrustum::Quantity) < m_PlaneQuantity)
    {
        // ƽ��ͷ��ƽ����ܲ��Ӷ�ջ��ɾ����
        --m_PlaneQuantity;
    }
}

bool Rendering::CullerImpl
    ::IsVisible (const Bound& bound)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    if (bound.GetRadius() <= Math::sm_ZeroTolerance)
    {
        // �ڵ���һ������ڵ㲻�ɼ���
        return false;
    }

    // �����ѹ���ƽ�濪ʼ,�������Լ������ƽ��
	auto index = m_PlaneQuantity - 1;
	auto mask = (1 << index);

    for (; 0 <= index; --index)
    {
        if (m_PlaneState & mask)
        {
			auto side = bound.WhichSide(m_Plane[index]);

            if (side ==  Mathematics::NumericalValueSymbol::Negative)
            {
                // ������ƽ��ĸ��ߣ������޳���
                return false;
            }

            if (side ==  Mathematics::NumericalValueSymbol::Positive)
            {
                // ������ƽ������ߡ�û�б�Ҫ��ƽ��Ƚ��Ӷ���,���Խ�����Ϊ�ǻ��
                m_PlaneState &= ~mask;
            }
        }
   
        mask >>= 1;
    }

    return true;
}

bool Rendering::CullerImpl
    ::IsVisible (int numVertices, const APoint* vertices, bool ignoreNearPlane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    // �����Զ������һ�����ʱ����������ignoreNearPlaneӦ������Ϊ��true����
    // ��ͱ����˵������ͼ�еĽ�����(��+��/��/��/��),�����۾�������ƽ��֮������������
    // �����������,����ϣ�����ϵͳ��������ڡ�
    // �������ͨ��������������ƶ�ͨ����ڴӵ�ǰ�������ڵ�����

    // �����ѹ���ƽ�濪ʼ,�������Լ������ƽ��
    for (auto index = m_PlaneQuantity - 1;0 <= index;--index)
    {
        const auto& plane = m_Plane[index];
        if (ignoreNearPlane && index == System::EnumCastUnderlying(ViewFrustum::DirectionMin))
        {
            continue;
        }

		auto which = numVertices;
        for (auto j = 0; j < numVertices; ++j)
        {
			auto side = plane.WhichSide(vertices[j]);
            if (side !=  Mathematics::NumericalValueSymbol::Negative)
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

Mathematics::NumericalValueSymbol Rendering::CullerImpl
    ::WhichSide (const Plane& plane) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    
    // ƽ����N * (X - C) = 0,����*��ʾ�����
    // �з��ž���������λ��E��ƽ����N * (E - C)��
	auto nDotEMinusC = plane.DistanceTo(m_Camera->GetPosition());

	auto normal = plane.GetNormal();
	auto nDotDirection = Dot(normal,m_Camera->GetDirectionVector());
	auto nDotUp = Dot(normal, m_Camera->GetUpVector());
	auto nDotRight = Dot(normal, m_Camera->GetRightVector());
	auto directionRatio = m_Frustum.GetDirectionMax() / m_Frustum.GetDirectionMin();

	auto positive = 0;
	auto negative = 0;

    // ����ƽ�涥�㡣
	auto pDirectionMin = m_Frustum.GetDirectionMin() * nDotDirection;
	auto nearUpMin = m_Frustum.GetUpMin() * nDotUp;
	auto nearUpMax = m_Frustum.GetUpMax() * nDotUp;
	auto nearRightMin = m_Frustum.GetRightMin() * nDotRight;
	auto nearRightMax = m_Frustum.GetRightMax() * nDotRight;

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
	auto pDirectionMax = m_Frustum.GetDirectionMax() * nDotDirection;
	auto farUpMin = directionRatio * nearUpMin;
	auto farUpMax = directionRatio * nearUpMax;
	auto farRightMin = directionRatio * nearRightMin;
	auto farRightMax = directionRatio * nearRightMax;

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

void Rendering::CullerImpl
    ::Clear ()
{
    RENDERING_CLASS_IS_VALID_1;

    m_VisibleSet.Clear();
}

int  Rendering::CullerImpl
    ::GetNumVisible () const
{
    RENDERING_CLASS_IS_VALID_1;

    return m_VisibleSet.GetNumVisible ();
}

const Rendering::ConstVisualSmartPointer  Rendering::CullerImpl
    ::GetVisible (int index) const
{
    RENDERING_CLASS_IS_VALID_1;

    return m_VisibleSet.GetVisible (index);

}

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl
	::begin()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VisibleSet.begin();
}

Rendering::CullerImpl::VisualContainerIter Rendering::CullerImpl
	::end()
{
	RENDERING_CLASS_IS_VALID_1;

	return m_VisibleSet.end();
}
