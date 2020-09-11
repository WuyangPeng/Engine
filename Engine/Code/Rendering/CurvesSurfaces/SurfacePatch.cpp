// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/25 17:46)

#include "Rendering/RenderingExport.h"

#include "SurfacePatch.h" 
#include "Detail/SurfacePatchImpl.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

using std::make_shared;
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
#include SYSTEM_WARNING_DISABLE(26496)
CORE_TOOLS_RTTI_DEFINE(Rendering, SurfacePatch);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, SurfacePatch);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, SurfacePatch); 
CORE_TOOLS_IMPL_NON_OBJECT_PTR_DEFAULT_STREAM(Rendering, SurfacePatch);

COPY_CONSTRUCTION_DEFINE_WITH_PARENT(Rendering, SurfacePatch);

Rendering::SurfacePatch
	::SurfacePatch(float uMin, float uMax, float vMin, float vMax, bool rectangular)
	:ParentType{ "SurfacePatch" }, m_Impl{ make_shared<ImplType>(uMin,uMax,vMin,vMax,rectangular) }
{
	RENDERING_SELF_CLASS_IS_VALID_1;
}
 

#ifdef OPEN_CLASS_INVARIANT
CLASS_INVARIANT_PARENT_AND_IMPL_IS_VALID_DEFINE(Rendering, SurfacePatch)

bool Rendering::SurfacePatch
	::IsParameterValid( float u, float v ) const noexcept
{
	RENDERING_CLASS_IS_VALID_CONST_1;

	if(m_Impl->GetUMin() <= u && u <= m_Impl->GetUMax() && m_Impl->GetVMin() <= v && v <= m_Impl->GetVMax())
	{
		if(!m_Impl->IsRectangular())
		{
			if((m_Impl->GetVMax() - m_Impl->GetVMin()) * (u - m_Impl->GetUMin()) + (m_Impl->GetUMax() - m_Impl->GetUMin()) * (v - m_Impl->GetVMax()) <= 0)
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
#endif // OPEN_CLASS_INVARIANT

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch,GetUMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch,GetUMax, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch,GetVMin, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch,GetVMax, float)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Rendering, SurfacePatch,IsRectangular, bool)

const Rendering::SurfacePatch::AVector Rendering::SurfacePatch
	::GetTangent0(float u, float v) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_2(IsParameterValid(u,v),"��������Ч\n");

	AVector tangent0 = GetDerivativesU(u, v);
	tangent0.Normalize();
	return tangent0;
}

const Rendering::SurfacePatch::AVector Rendering::SurfacePatch
	::GetTangent1(float u, float v) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;	
	RENDERING_ASSERTION_2(IsParameterValid(u,v),"��������Ч\n");

	AVector tangent0 = GetDerivativesU(u, v);
	AVector tangent1 = GetDerivativesV(u, v);
	tangent0.Normalize();
	AVector normal = UnitCross(tangent0,tangent1);
	tangent1 = Cross(normal,tangent0);

	return tangent1;
}

const Rendering::SurfacePatch::AVector Rendering::SurfacePatch
	::GetNormal(float u, float v) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_2(IsParameterValid(u,v),"��������Ч\n");

	AVector tangent0 = GetDerivativesU(u, v);
	AVector tangent1 = GetDerivativesV(u, v);

	// ����������� GetFrame һ�¡�
	tangent0.Normalize(); 

	AVector normal = UnitCross( tangent0,tangent1);

	return normal;
}

const Rendering::SurfacePatchFrame Rendering::SurfacePatch
	::GetFrame(float u, float v) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_2(IsParameterValid(u,v),"��������Ч\n");

	APoint position = GetPosition(u, v);

	AVector tangent0 = GetDerivativesU(u, v);
	AVector tangent1 = GetDerivativesV(u, v);
	tangent0.Normalize();
	AVector normal = UnitCross(tangent0, tangent1);

	// ��һ��һ�׵��������������ġ�
	// ���¼���T1��ʹ{T0,T1,N}��һ����׼�������ϡ�
	tangent1 = Cross(normal,tangent0);

	return SurfacePatchFrame(position, tangent0, tangent1, normal);
}

const Rendering::PrincipalCurvatureInfo Rendering::SurfacePatch
	::ComputePrincipalCurvatureInfo(float u, float v) const
{
	RENDERING_CLASS_IS_VALID_CONST_1;
	RENDERING_ASSERTION_2(IsParameterValid(u,v),"��������Ч\n");

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
	AVector derivativesU = GetDerivativesU(u, v);
	AVector derivativesV = GetDerivativesV(u, v);
	AVector derivativesUU = GetDerivativesUU(u, v);
	AVector derivativesUV = GetDerivativesUV(u, v);
	AVector derivativesVV = GetDerivativesVV(u, v);

	// �������������
	Mathematics::Matrix2f metricTensor;
	metricTensor(0,0) = Dot(derivativesU,derivativesU);
	metricTensor(0,1) = Dot(derivativesU,derivativesV);
	metricTensor(1,0) = metricTensor(0,1);
	metricTensor(1,1) = Dot( derivativesV,derivativesV);

	// ��������������
	AVector normal = UnitCross(derivativesU,derivativesV);
	Mathematics::Matrix2f curvatureTensor;
	curvatureTensor(0,0) = -Dot(normal,derivativesUU);
	curvatureTensor(0,1) = -Dot(normal,derivativesUV);
	curvatureTensor(1,0) = curvatureTensor(0,1);
	curvatureTensor(1,1) = -Dot(normal,derivativesVV);

	// ��������ʽΪ 0 = det(B-kG) = c2*k^2+c1*k+c0.
	const float constant = curvatureTensor(0,0) * curvatureTensor(1,1) -
		             curvatureTensor(0,1) * curvatureTensor(1,0);
	const float once = 2.0f * curvatureTensor(0,1) * metricTensor(0,1) -
		         curvatureTensor(0,0) * metricTensor(1,1) -
				 curvatureTensor(1,1) * metricTensor(0,0);
	const float twice = metricTensor(0,0) * metricTensor(1,1) -
		          metricTensor(0,1) * metricTensor(1,0);

	// �����ʵ���������ʽ�ĸ���
	const float discriminant =
		Mathematics::FloatMath::Sqrt(Mathematics::FloatMath::FAbs(once * once - 4.0f * constant * twice));
	const float principalCurvature0 = -0.5f * (once + discriminant);
	const float principalCurvature1 = 0.5f * (-once + discriminant);
		
	// ��������(B-kG)w = 0�Ľ�,
	// w1 = (b12-k1*g12,-(b11-k1*g11)) �� (b22-k1*g22,-(b12-k1*g12))
	float a0 = curvatureTensor(0,1) - principalCurvature0 * metricTensor(0,1);
	float a1 = principalCurvature0 * metricTensor(0,0) - curvatureTensor(0,0);
	float length = Mathematics::FloatMath::Sqrt(a0 * a0 + a1 * a1);
        AVector principalDirection0{ Mathematics ::Float::g_Zero };
	if (Mathematics::FloatMath::GetZeroTolerance() <= length)
	{
		principalDirection0 = a0 * derivativesU + a1 * derivativesV;
	}
	else
	{
		a0 = curvatureTensor(1,1) - principalCurvature0 * metricTensor(1,1);
		a1 = principalCurvature0*metricTensor(0,1) - curvatureTensor(0,1);
		length = Mathematics::FloatMath::Sqrt(a0 * a0 + a1 * a1);
		if (Mathematics::FloatMath::GetZeroTolerance() <= length)
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
	AVector principalDirection1 = Cross(principalDirection0,normal);

	return PrincipalCurvatureInfo(principalCurvature0, principalCurvature1, principalDirection0, principalDirection1);
}

#include STSTEM_WARNING_POP