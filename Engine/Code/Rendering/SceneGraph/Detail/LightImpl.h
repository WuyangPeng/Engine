// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/19 19:17)

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
		
		// 光类型,目前只有一个传统的类型。默认值是LightType::Ambient。
		void SetType(LightType type);
		LightType GetType() const;

		// 一个帮助函数,允许您设置m_Angle和自动计算m_CosAngle和m_SinAngle。
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

		// 一个帮助函数，当你设置方向向量时，自动计算向上和向右向量。
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
		// 光的颜色
		Colour m_Ambient;   // 默认: (0,0,0,1)
		Colour m_Diffuse;   // 默认: (0,0,0,1)
		Colour m_Specular;  // 默认: (0,0,0,1)		
 
		// 衰减通常指定为一个调节器
		//     m = 1 / (C + L * d + Q * d * d)
		// 这里C是常量系数，L是线性系数，Q是二次系数，
		// 和d是顶点位置同光位置的距离。
		// 允许一个线性调整强度因子,选择使用
		//     m = I / (C + L * d + Q * d * d)
		// 代替，这里I是一个强度因子。
		float m_Constant;   // 默认: 1
		float m_Linear;     // 默认: 0
		float m_Quadratic;  // 默认: 0
		float m_Intensity;  // 默认: 1
		
		// 位置光源的参数。锥角必须满足在弧度0 < Angle <= pi。
		float m_Angle;     // 默认: pi
		float m_CosAngle;  // 默认: -1
		float m_SinAngle;  // 默认:  0
		float m_Exponent;  // 默认:  1		
		
		// 虽然标准的方向光源和位置光源只需要一个方向向量，
		// 但为了允许新类型的派生类的光源使用一个完整的坐标系，
		// 光源提供了这样一个存储框架。光源框架总是在世界坐标。
		//   默认 position  P = (0,0,0)
		//   默认 direction D = (0,0,-1)
		//   默认 up        U = (0,1,0)
		//   默认 right     R = (1,0,0)
		// 集合{ D,U,R }必须是一个右手标准正交集合。
		// 也就是说,每个向量是长度单位,向量是相互垂直,R = Cross(D,U)。
		APoint m_Position;
		AVector m_DirectionVector;
		AVector m_UpVector;
		AVector m_RightVector;
				
		LightType m_LightType;
		float m_Epsilon;
	};
}

#endif // RENDERING_SCENE_GRAPH_LIGHT_IMPL_H
