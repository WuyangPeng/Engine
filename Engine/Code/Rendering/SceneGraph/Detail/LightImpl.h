// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/19 19:17)

#ifndef RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
#define RENDERING_SCENE_GRAPH_LIGHT_IMPL_H

#include "Rendering/RenderingDll.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Colour.h" 
#include "Rendering/SceneGraph/Flags/LightFlags.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE LightImpl
	{
	public:
		using ClassType = LightImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using APoint = Mathematics::APoint<float>;
		using AVector = Mathematics::AVector<float>;
		using Math = Mathematics::Math<float>;
		using Colour = Colour<float>;

	public: 
		explicit LightImpl(LightType type = LightType::Ambient,float epsilon = Math::GetZeroTolerance());

		CLASS_INVARIANT_DECLARE;		 
		
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

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;

	private:		
		// �����ɫ
		Colour m_Ambient;   // Ĭ��: (0,0,0,1)
		Colour m_Diffuse;   // Ĭ��: (0,0,0,1)
		Colour m_Specular;  // Ĭ��: (0,0,0,1)		
 
		// ˥��ͨ��ָ��Ϊһ��������
		//     m = 1 / (C + L * d + Q * d * d)
		// ����C�ǳ���ϵ����L������ϵ����Q�Ƕ���ϵ����
		// ��d�Ƕ���λ��ͬ��λ�õľ��롣
		// ����һ�����Ե���ǿ������,ѡ��ʹ��
		//     m = I / (C + L * d + Q * d * d)
		// ���棬����I��һ��ǿ�����ӡ�
		float m_Constant;   // Ĭ��: 1
		float m_Linear;     // Ĭ��: 0
		float m_Quadratic;  // Ĭ��: 0
		float m_Intensity;  // Ĭ��: 1
		
		// λ�ù�Դ�Ĳ�����׶�Ǳ��������ڻ���0 < Angle <= pi��
		float m_Angle;     // Ĭ��: pi
		float m_CosAngle;  // Ĭ��: -1
		float m_SinAngle;  // Ĭ��:  0
		float m_Exponent;  // Ĭ��:  1		
		
		// ��Ȼ��׼�ķ����Դ��λ�ù�Դֻ��Ҫһ������������
		// ��Ϊ�����������͵�������Ĺ�Դʹ��һ������������ϵ��
		// ��Դ�ṩ������һ���洢��ܡ���Դ����������������ꡣ
		//   Ĭ�� position  P = (0,0,0)
		//   Ĭ�� direction D = (0,0,-1)
		//   Ĭ�� up        U = (0,1,0)
		//   Ĭ�� right     R = (1,0,0)
		// ����{ D,U,R }������һ�����ֱ�׼�������ϡ�
		// Ҳ����˵,ÿ�������ǳ��ȵ�λ,�������໥��ֱ,R = Cross(D,U)��
		APoint m_Position;
		AVector m_DirectionVector;
		AVector m_UpVector;
		AVector m_RightVector;
				
		LightType m_LightType;
		float m_Epsilon;
	};
}

#endif // RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
