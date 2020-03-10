// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 14:30)

#ifndef RENDERING_SHADERS_ALPHA_STATE_IMPL_H
#define RENDERING_SHADERS_ALPHA_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Shaders/Flags/AlphaStateFlags.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE AlphaStateImpl
	{
	public:
		using ClassType = AlphaStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using Colour = Colour<float>;
		using SourceBlendMode = AlphaStateFlags::SourceBlendMode;
		using DestinationBlendMode = AlphaStateFlags::DestinationBlendMode;
		using CompareMode = AlphaStateFlags::CompareMode;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		AlphaStateImpl(); 

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;

		bool IsBlendEnabled() const;
		SourceBlendMode GetSourceBlend() const;
		DestinationBlendMode GetDestinationBlend() const;
		bool IsCompareEnabled() const;
		CompareMode GetCompare() const;
		float GetReference() const;
		const Colour GetConstantColor() const;

		void SetBlendEnabled(bool blendEnabled);		
		void SetSourceBlend(SourceBlendMode mode);		
		void SetDestinationBlend(DestinationBlendMode mode);		
		void SetCompareEnabled(bool compareEnabled);		
		void SetCompare(CompareMode mode);		
		void SetReference(float reference);		
		void SetConstantColor(const Colour& value);

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:
		bool m_BlendEnabled; // 默认: false
		SourceBlendMode m_SourceBlend; // 默认: SourceBlendMode::SourceAlpha
		DestinationBlendMode m_DestinationBlend; // 默认: DestinationBlendMode::OneMinusSourceAlpha
		bool m_CompareEnabled; // 默认: false
		CompareMode m_Compare; // 默认: CompareMode::Always
		float m_Reference; // 默认: 0, 总是在[0,1]
		Colour m_ConstantColor; // 默认: (0,0,0,0)
	};
}

#endif // RENDERING_SHADERS_ALPHA_STATE_IMPL_H
