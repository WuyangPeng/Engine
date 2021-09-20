// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:30)

#ifndef RENDERING_SHADERS_STENCIL_STATE_H
#define RENDERING_SHADERS_STENCIL_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/StencilStateFlags.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"


 
EXPORT_SHARED_PTR(Rendering, StencilStateImpl, RENDERING_DEFAULT_DECLARE);
namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE StencilState : public CoreTools::Object
	{
	public:
            void Swap(StencilState& rhs) noexcept;
            
                public:
                    TYPE_DECLARE(StencilState);
                    using ClassShareType = CoreTools::CopyUnsharedClasses;
                    ~StencilState() noexcept;
                    StencilState(const StencilState& rhs);
                    StencilState& operator=(const StencilState& rhs);
                    StencilState(StencilState&& rhs) noexcept;
                    StencilState& operator=(StencilState&& rhs) noexcept;
		using ParentType = Object;
		using CompareMode = StencilStateFlags::CompareMode;
		using OperationType = StencilStateFlags::OperationType;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		StencilState();
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(StencilState); 

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
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		using ImplPtr = std::shared_ptr<ImplType>;    private:        ImplPtr impl;
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(StencilState);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( StencilState);
}

#endif // RENDERING_SHADERS_STENCIL_STATE_H
