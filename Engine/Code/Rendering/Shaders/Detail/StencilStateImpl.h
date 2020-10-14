// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:01)

#ifndef RENDERING_SHADERS_STENCIL_STATE_IMPL_H
#define RENDERING_SHADERS_STENCIL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/Flags/StencilStateFlags.h"
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
	class RENDERING_HIDDEN_DECLARE StencilStateImpl
	{
	public:
		using ClassType = StencilStateImpl;
		using BufferSource = CoreTools::BufferSource;
		using BufferTarget = CoreTools::BufferTarget;
		using CompareMode = StencilStateFlags::CompareMode;
		using OperationType = StencilStateFlags::OperationType;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		StencilStateImpl();

		CLASS_INVARIANT_DECLARE;

		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		bool IsEnabled() const;		
		CompareMode GetCompare() const;
		unsigned int GetReference() const;
		unsigned int GetMask() const;
		unsigned int GetWriteMask() const;
		OperationType GetOnFail() const;
		OperationType GetOnZFail() const;
		OperationType GetOnZPass() const;

		void SetEnabled(bool enabled);
		void SetCompare(CompareMode compare);		
		void SetReference(unsigned int reference);		
		void SetMask(unsigned int mask);		
		void SetWriteMask(unsigned int writeMask);		
		void SetOnFail(OperationType onFail);		
		void SetOnZFail(OperationType onZFail);		
		void SetOnZPass(OperationType onZPass);

		void SaveState(WriteFileManager& manager) const;
		void LoadState(ReadFileManager& manager);

	private:
		bool m_Enabled; // 默认: false
		CompareMode m_Compare; // 默认: CompareMode::Never
		unsigned int m_Reference; // 默认: 0
		unsigned int m_Mask; // 默认: UINT_MAX (0xFFFFFFFF)
		unsigned int m_WriteMask; // 默认: UINT_MAX (0xFFFFFFFF)
		OperationType m_OnFail; // 默认: OperationType::Keep
		OperationType m_OnZFail; // 默认: OperationType::Keep
		OperationType m_OnZPass; // 默认: OperationType::Keep
	};
}

#endif // RENDERING_SHADERS_STENCIL_STATE_IMPL_H
