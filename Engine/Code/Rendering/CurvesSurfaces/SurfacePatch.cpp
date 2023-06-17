///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:00)

#include "Rendering/RenderingExport.h"

#include "SurfacePatch.h"
#include "Detail/SurfacePatchImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/Matrix2Detail.h"

using std::make_shared;

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, SurfacePatch)

CORE_TOOLS_RTTI_DEFINE(Rendering, SurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SurfacePatch);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, SurfacePatch);

Rendering::SurfacePatch::SurfacePatch(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CORE_TOOLS_WITH_IMPL_OBJECT_GET_STREAMING_SIZE_DEFINE(Rendering, SurfacePatch)
CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, SurfacePatch)
CORE_TOOLS_WITH_IMPL_OBJECT_SAVE_DEFINE(Rendering, SurfacePatch)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, SurfacePatch)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, SurfacePatch)
CORE_TOOLS_WITH_IMPL_OBJECT_LOAD_DEFINE(Rendering, SurfacePatch)

Rendering::SurfacePatch::SurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular)
    : ParentType{ "SurfacePatch" }, impl{ uMin, uMax, vMin, vMax, rectangular }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, SurfacePatch)

bool Rendering::SurfacePatch::IsParameterValid(float u, float v) const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (impl->GetUMin() <= u && u <= impl->GetUMax() && impl->GetVMin() <= v && v <= impl->GetVMax())
    {
        if (!impl->IsRectangular())
        {
            if ((impl->GetVMax() - impl->GetVMin()) * (u - impl->GetUMin()) + (impl->GetUMax() - impl->GetUMin()) * (v - impl->GetVMax()) <= 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch, GetUMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch, GetUMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch, GetVMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch, GetVMax, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch, IsRectangular, bool)

Rendering::SurfacePatch::AVector Rendering::SurfacePatch::GetTangent0(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    auto tangent0 = GetDerivativesU(u, v);
    tangent0.Normalize();
    return tangent0;
}

Rendering::SurfacePatch::AVector Rendering::SurfacePatch::GetTangent1(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    auto tangent0 = GetDerivativesU(u, v);
    auto tangent1 = GetDerivativesV(u, v);
    tangent0.Normalize();
    const auto normal = UnitCross(tangent0, tangent1);
    tangent1 = Cross(normal, tangent0);

    return tangent1;
}

Rendering::SurfacePatch::AVector Rendering::SurfacePatch::GetNormal(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    auto tangent0 = GetDerivativesU(u, v);
    const auto tangent1 = GetDerivativesV(u, v);

    // ����������� GetFrame һ�¡�
    tangent0.Normalize();

    auto normal = UnitCross(tangent0, tangent1);

    return normal;
}

Rendering::SurfacePatchFrame Rendering::SurfacePatch::GetFrame(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    const auto position = GetPosition(u, v);

    auto tangent0 = GetDerivativesU(u, v);
    auto tangent1 = GetDerivativesV(u, v);
    tangent0.Normalize();
    const auto normal = UnitCross(tangent0, tangent1);

    // ��һ��һ�׵��������������ġ�
    // ���¼���T1��ʹ{T0,T1,N}��һ����׼�������ϡ�
    tangent1 = Cross(normal, tangent0);

    return SurfacePatchFrame{ position, tangent0, tangent1, normal };
}

Rendering::PrincipalCurvatureInfo Rendering::SurfacePatch::ComputePrincipalCurvatureInfo(float u, float v) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_2(IsParameterValid(u, v), "��������Ч\n");

    // ����:  T0 = dP/du = (x_u,y_u,z_u), T1 = dP/dv = (x_v,y_v,z_v)
    // ����:    N = Cross(T0,T1)/Length(Cross(T0,T1))
    // ��������:    G = +-                      -+
    //                  | Dot(T0,T0)  Dot(T0,T1) |
    //                  | Dot(T1,T0)  Dot(T1,T1) |
    //                  +-                      -+

    // ��������:  B = +-                          -+
    //                | -Dot(N,T0_u)  -Dot(N,T0_v) |
    //                | -Dot(N,T1_u)  -Dot(N,T1_v) |
    //                +-                          -+

    // ������kΪ��������ֵ
    //
    //     Bw = kGw
    // ���k�������Լ�w=(a,b)����Ӧ�Ľ���������� Bw = kGw��
    // ��������3Dʸ��Ϊ d = a*U+b*V��
    // k1��k2�������ʡ�ƽ������Ϊ(k1+k2)/2 �͸�˹������k1*k2��

    // ���㵼��
    const auto derivativesU = GetDerivativesU(u, v);
    const auto derivativesV = GetDerivativesV(u, v);
    const auto derivativesUU = GetDerivativesUU(u, v);
    const auto derivativesUV = GetDerivativesUV(u, v);
    const auto derivativesVV = GetDerivativesVV(u, v);

    // �������������
    Mathematics::Matrix2F metricTensor{};
    metricTensor(0, 0) = Dot(derivativesU, derivativesU);
    metricTensor(0, 1) = Dot(derivativesU, derivativesV);
    metricTensor(1, 0) = metricTensor(0, 1);
    metricTensor(1, 1) = Dot(derivativesV, derivativesV);

    // ��������������
    const auto normal = UnitCross(derivativesU, derivativesV);
    Mathematics::Matrix2F curvatureTensor{};
    curvatureTensor(0, 0) = -Dot(normal, derivativesUU);
    curvatureTensor(0, 1) = -Dot(normal, derivativesUV);
    curvatureTensor(1, 0) = curvatureTensor(0, 1);
    curvatureTensor(1, 1) = -Dot(normal, derivativesVV);

    // ��������ʽΪ 0 = det(B-kG) = c2*k^2+c1*k+c0.
    const auto constant = curvatureTensor(0, 0) * curvatureTensor(1, 1) - curvatureTensor(0, 1) * curvatureTensor(1, 0);
    const auto once = 2.0f * curvatureTensor(0, 1) * metricTensor(0, 1) - curvatureTensor(0, 0) * metricTensor(1, 1) - curvatureTensor(1, 1) * metricTensor(0, 0);
    const auto twice = metricTensor(0, 0) * metricTensor(1, 1) - metricTensor(0, 1) * metricTensor(1, 0);

    // �����ʵ���������ʽ�ĸ���
    const auto discriminant = Mathematics::MathF::Sqrt(Mathematics::MathF::FAbs(once * once - 4.0f * constant * twice));
    const auto principalCurvature0 = -0.5f * (once + discriminant);
    const auto principalCurvature1 = 0.5f * (-once + discriminant);

    // ��������(B-kG)w = 0�Ľ�,
    // w1 = (b12-k1*g12,-(b11-k1*g11)) �� (b22-k1*g22,-(b12-k1*g12))
    auto a0 = curvatureTensor(0, 1) - principalCurvature0 * metricTensor(0, 1);
    auto a1 = principalCurvature0 * metricTensor(0, 0) - curvatureTensor(0, 0);
    auto length = Mathematics::MathF::Sqrt(a0 * a0 + a1 * a1);
    AVector principalDirection0{ Mathematics::AVectorF::GetZero() };
    if (Mathematics::MathF::GetZeroTolerance() <= length)
    {
        principalDirection0 = a0 * derivativesU + a1 * derivativesV;
    }
    else
    {
        a0 = curvatureTensor(1, 1) - principalCurvature0 * metricTensor(1, 1);
        a1 = principalCurvature0 * metricTensor(0, 1) - curvatureTensor(0, 1);
        length = Mathematics::MathF::Sqrt(a0 * a0 + a1 * a1);
        if (Mathematics::MathF::GetZeroTolerance() <= length)
        {
            principalDirection0 = a0 * derivativesU + a1 * derivativesV;
        }
        else
        {
            // Umbilic������ֲ����壬���ⷽ��Ϊ������
            principalDirection0 = derivativesU;
        }
    }
    principalDirection0.Normalize();

    // �ڶ������ǵ�һ���ߺͷ��ߵĲ��
    const auto principalDirection1 = Cross(principalDirection0, normal);

    return PrincipalCurvatureInfo{ principalCurvature0, principalCurvature1, principalDirection0, principalDirection1 };
}
