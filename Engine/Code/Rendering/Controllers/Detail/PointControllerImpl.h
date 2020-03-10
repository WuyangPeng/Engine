// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 10:15)

#ifndef RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
  
#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/AVector.h"

#include <vector>

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;	
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE PointControllerImpl
	{
	public:
		using ClassType = PointControllerImpl;
		using AVector = Mathematics::AVectorf;

	public:	
		explicit PointControllerImpl(int numPoints);
		PointControllerImpl();

		CLASS_INVARIANT_DECLARE;

 		// ���˶����ڸ�ϵͳ��ģ�Ϳռ䡣�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
		// ���е����һ��������Ӧ�ó���
		// �����ѡ���ϵͳ��ԭ��Ϊ����������ĺ�
		// �������Ӧ�ڹ���������������
		int GetNumPoints() const;
		float GetPointLinearSpeed(int index) const;
		float GetPointAngularSpeed(int index) const;
		const AVector GetPointLinearAxis(int index) const;
		const AVector GetPointAngularAxis(int index) const;

		void SetPointLinearSpeed(int index, float pointLinearSpeed);
		void SetPointAngularSpeed(int index, float pointAngularSpeed);
		void SetPointLinearAxis(int index, const AVector& pointLinearAxis);
		void SetPointAngularAxis(int index, const AVector& pointAngularAxis);

		float GetSystemLinearSpeed() const;
		void SetSystemLinearSpeed(float systemLinearSpeed);
		float GetSystemAngularSpeed() const;
		void SetSystemAngularSpeed(float systemAngularSpeed);
		const AVector GetSystemLinearAxis() const;
		void SetSystemLinearAxis(const AVector& systemLinearAxis);
		const AVector GetSystemAngularAxis() const;
		void SetSystemAngularAxis(const AVector& systemAngularAxis);

		int GetStreamingSize() const;
		void Save(CoreTools::BufferTarget& target) const;
		void Load(CoreTools::BufferSource& source);
		
	private:	
		// ϵͳ���˶����ھֲ����ꡣ�ٶ�ʸ��ӦΪ��λ�ĳ��ȡ�
		float m_SystemLinearSpeed;
		float m_SystemAngularSpeed;
		AVector m_SystemLinearAxis;
		AVector m_SystemAngularAxis;

		int m_NumPoints;
		std::vector<float> m_PointLinearSpeed;
		std::vector<float> m_PointAngularSpeed;
		std::vector<AVector> m_PointLinearAxis;
		std::vector<AVector> m_PointAngularAxis;
	};
}

#endif // RENDERING_CONTROLLERS_POINT_CONTROLLER_IMPL_H
