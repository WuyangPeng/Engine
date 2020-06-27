// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/22 11:21)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_H
#define RENDERING_SCENE_GRAPH_LIGHT_H

#include "Rendering/RenderingDll.h"

#include "Flags/LightFlags.h"
#include "Rendering/DataTypes/Colour.h" 
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "CoreTools/ObjectSystems/Object.h"

RENDERING_EXPORT_SHARED_PTR(LightImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE Light : public CoreTools::Object
	{
	public:
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(Light);
		using ParentType = Object;
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;
		using Math = Mathematics::Math<float>;
		using Colour = Colour<float>;

	public:
		explicit Light(LightType type = LightType::Ambient,float epsilon = Math::sm_ZeroTolerance);
		virtual ~Light();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(Light); 

		// ������,Ŀǰֻ��һ����ͳ�����͡�Ĭ��ֵ��LightType::Ambient��
		void SetType(LightType type);
		LightType GetType() const;

		// һ����������,����������m_Angle���Զ�����m_CosAngle��m_SinAngle��
		void SetAngle(float angle);

		void SetExponent(float exponent);

		float GetAngle() const;
		float GetCosAngle() const;
		float GetSinAngle() const;
		float GetExponent() const;

		void SetAmbient(const Colour& ambient);
		void SetDiffuse(const Colour& diffuse);
		void SetSpecular(const Colour& specular);

		const Colour GetAmbient() const;
		const Colour GetDiffuse() const;
		const Colour GetSpecular() const;

		const APoint GetPosition() const;
		const AVector GetDirectionVector() const;
		const AVector GetUpVector() const;
		const AVector GetRightVector() const;

		void SetPosition(const APoint& point);
		void SetVector(const AVector& up, const AVector& right, const AVector& direction);

		// һ�������������������÷�������ʱ���Զ��������Ϻ�����������
		void SetDirection(const AVector& direction);

		void SetAttenuation(float constant, float linear, float quadratic, float intensity);

		float GetConstant() const;
		float GetLinear() const;
		float GetQuadratic() const;
		float GetIntensity() const;

	private:
		IMPL_TYPE_DECLARE(Light);
	};

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(Light);
#include STSTEM_WARNING_POP

	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, Light); 
}

#endif // RENDERING_SCENE_GRAPH_LIGHT_H
