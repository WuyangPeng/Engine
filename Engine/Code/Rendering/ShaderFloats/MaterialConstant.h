// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/23 17:02)

#ifndef RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H
#define RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "Rendering/SceneGraph/Material.h"
#include "ShaderFloat.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

RENDERING_EXPORT_SHARED_PTR(MaterialConstantImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE MaterialConstant : public ShaderFloat
	{
	public:
		OLD_COPY_UNSHARE_CLASSES_TYPE_DECLARE(MaterialConstant);
		using ParentType = ShaderFloat;

	public:
		explicit MaterialConstant(const MaterialSmartPointer& Material);
            ~MaterialConstant() = default;
                MaterialConstant(MaterialConstant&&) noexcept = default;
            MaterialConstant& operator=(MaterialConstant&&) noexcept = default;

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(MaterialConstant);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;

		  void Update(const Visual* visual, const Camera* camera) = 0;

		  void SetNumRegisters(int numRegisters) override;

		const ConstMaterialSmartPointer GetMaterial() const;

	private:
		constexpr static auto sm_NumRegisters = 1;

	private:
		IMPL_TYPE_DECLARE(MaterialConstant);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
	CORE_TOOLS_STREAM_REGISTER(MaterialConstant);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Fourth, MaterialConstant);
}
#include STSTEM_WARNING_POP
#endif // RENDERING_SHADER_FLOATS_MATERIAL_CONSTANT_H
