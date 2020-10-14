// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:17)

#ifndef RENDERING_SHADERS_OFFSET_STATE_H
#define RENDERING_SHADERS_OFFSET_STATE_H

#include "Rendering/RenderingDll.h"

#include "Flags/DepthStateFlags.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"


namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

RENDERING_EXPORT_SHARED_PTR(OffsetStateImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE OffsetState : public CoreTools::Object
	{
	public:
            COPY_UNSHARE_CLASSES_TYPE_DECLARE(OffsetState, DESTRUCTOR_STATEMENT);
		using ParentType = Object;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		OffsetState();
	 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(OffsetState); 

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
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		IMPL_TYPE_DECLARE(OffsetState);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(OffsetState);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( OffsetState);
}

#endif // RENDERING_SHADERS_OFFSET_STATE_H
