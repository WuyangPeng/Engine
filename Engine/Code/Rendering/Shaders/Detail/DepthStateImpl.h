// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.3 (2019/07/24 14:32)

#ifndef RENDERING_SHADERS_DEPTH_STATE_IMPL_H
#define RENDERING_SHADERS_DEPTH_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/DepthStateFlags.h"
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
	class RENDERING_HIDDEN_DECLARE DepthStateImpl
	{
	public:
		using ClassType = DepthStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using CompareMode = DepthStateFlags::CompareMode;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
                DepthStateImpl() noexcept; 

		CLASS_INVARIANT_DECLARE;

		void Load(BufferSource& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		bool IsEnabled() const;
		bool IsWritable() const;
		CompareMode GetCompare() const;

		void SetEnabled(bool enabled);
		void SetWritable(bool writable);
		void SetCompare(CompareMode compare);

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:
		bool m_Enabled; // Ä¬ÈÏ: true
		bool m_Writable; // Ä¬ÈÏ: true
		CompareMode m_Compare; // Ä¬ÈÏ: CompareMode::LessEqual
	};
}

#endif // RENDERING_SHADERS_DEPTH_STATE_IMPL_H
