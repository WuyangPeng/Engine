// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:13)

#ifndef RENDERING_SHADERS_WIRE_STATE_IMPL_H
#define RENDERING_SHADERS_WIRE_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

namespace CoreTools
{
	class BufferSource;
	class BufferTarget;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE WireStateImpl
	{
	public:
		using ClassType = WireStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
                WireStateImpl() noexcept;

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(BufferTarget& target) const;
		int GetStreamingSize() const;

		bool IsEnabled() const noexcept;
                void SetEnabled(bool enabled) noexcept;

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:
		bool m_Enabled;  // ƒ¨»œ: false	
	};
}

#endif // RENDERING_SHADERS_WIRE_STATE_IMPL_H
