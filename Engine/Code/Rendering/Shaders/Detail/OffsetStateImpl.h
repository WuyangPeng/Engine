// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 14:33)

#ifndef RENDERING_SHADERS_OFFSET_STATE_IMPL_H
#define RENDERING_SHADERS_OFFSET_STATE_IMPL_H

#include "Rendering/RenderingDll.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE OffsetStateImpl
	{
	public:
		using ClassType = OffsetStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
                OffsetStateImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const; 

		bool IsFillEnabled() const;
		bool IsLineEnabled() const;
		bool IsPointEnabled() const;
		float GetScale() const;
		float GetBias() const;

		void SetFillEnabled(bool fillEnabled);
		void SetLineEnabled(bool lineEnabled);
		void SetPointEnabled(bool pointEnabled);
		void SetScale(float scale);
		void SetBias(float bias);

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:	
		// 设置是否应该为各种多边形绘图模式（填充，线，点）启用偏移。
		bool m_FillEnabled; // 默认: false
		bool m_LineEnabled; // 默认: false
		bool m_PointEnabled; // 默认: false
		
		// 偏移量是Scale * dZ + Bias * r，
		// 其中DZ是相对于聚屏幕空间区域深度的变化，
		// r是最小可分辨深度差异。负值表示移动多边形接近眼睛。
		float m_Scale; // 默认: 0
		float m_Bias; // 默认: 0
	}; 
}

#endif // RENDERING_SHADERS_OFFSET_STATE_IMPL_H
