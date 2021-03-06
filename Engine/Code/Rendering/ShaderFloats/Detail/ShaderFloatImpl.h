// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/23 16:48)

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
		// 寄存器的数量必须为正数。每个寄存器相当于四个浮点数。
		ShaderFloatImpl();
		explicit ShaderFloatImpl(int numRegisters); 
		explicit ShaderFloatImpl(const FloatVector& data);

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source); 
		void Save (const CoreTools::BufferTargetSharedPtr& target) const; 
		int GetStreamingSize () const;		

		// 对于延迟构造。
		void SetNumRegisters (int numRegisters);		
		
		int GetNumRegisters () const;
		const float* GetData () const;
		float* GetData ();
		
		// 由寄存器访问数据。SetRegister从data复制四个浮点值的副本到寄存器index。
		// SetRegisters从data复制mNumElements个浮点值到所有寄存器。
		// 类似的浮点值大小由Get*函数复制。
		void SetRegister (int index, const FloatVector& data);
		void SetRegister(int index, const AVector& vector);
		void SetRegister(int index, const APoint& point);
		void SetRegister(int index, const Colour& colour);
		void SetRegisters (const FloatVector& data);
		void SetRegisters(const Matrix& matrix);
		const FloatVector GetRegister (int index) const;
		const FloatVector GetRegisters () const;
		
		// 按索引访问数据。
		const float& operator[] (int index) const;
		float& operator[] (int index);

		// 该函数允许着色器常量的动态更新在渲染器调用VisualEffectInput::Enable函数。
		// 因此，数据传送到着色器程序尽可能晚在渲染通道发生。
		// 这是在绘图调用修改摄像机设置全局效果时非常有用。
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
