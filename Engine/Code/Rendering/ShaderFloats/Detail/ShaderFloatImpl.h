// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/23 16:48)

#ifndef RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H
#define RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Mathematics/Algebra/AVector.h"
#include "Rendering/DataTypes/Colour.h"

#include <vector>
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE ShaderFloatImpl
	{
	public:
		using ClassType = ShaderFloatImpl;
		using FloatVector = std::vector<float>;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using AVector = Mathematics::FloatAVector;
		using APoint = Mathematics::FloatAPoint;
		using Matrix = Mathematics::FloatMatrix;
		using Colour = Colour<float>;

	public:
		// �Ĵ�������������Ϊ������ÿ���Ĵ����൱���ĸ���������
		ShaderFloatImpl();
		explicit ShaderFloatImpl(int numRegisters); 
		explicit ShaderFloatImpl(const FloatVector& data);

		CLASS_INVARIANT_DECLARE;

		void Load (BufferSource& source); 
		void Save (const CoreTools::BufferTargetSharedPtr& target) const; 
		int GetStreamingSize () const;		

		// �����ӳٹ��졣
		void SetNumRegisters (int numRegisters);		
		
		int GetNumRegisters () const;
		const float* GetData () const;
		float* GetData ();
		
		// �ɼĴ����������ݡ�SetRegister��data�����ĸ�����ֵ�ĸ������Ĵ���index��
		// SetRegisters��data����mNumElements������ֵ�����мĴ�����
		// ���Ƶĸ���ֵ��С��Get*�������ơ�
		void SetRegister (int index, const FloatVector& data);
		void SetRegister(int index, const AVector& vector);
		void SetRegister(int index, const APoint& point);
		void SetRegister(int index, const Colour& colour);
		void SetRegisters (const FloatVector& data);
		void SetRegisters(const Matrix& matrix);
		const FloatVector GetRegister (int index) const;
		const FloatVector GetRegisters () const;
		
		// �������������ݡ�
		const float& operator[] (int index) const;
		float& operator[] (int index);

		// �ú���������ɫ�������Ķ�̬��������Ⱦ������VisualEffectInput::Enable������
		// ��ˣ����ݴ��͵���ɫ�����򾡿���������Ⱦͨ��������
		// �����ڻ�ͼ�����޸����������ȫ��Ч��ʱ�ǳ����á�
		void EnableUpdater();
		void DisableUpdater();
		bool AllowUpdater() const;

	private:
		static constexpr auto sm_FloatingPointSize = 4;

	private:
		FloatVector m_Data;
		bool m_AllowUpdater;
	};
}

#endif // RENDERING_SHADER_FLOATS_SHADER_FLOATS_IMPL_H
