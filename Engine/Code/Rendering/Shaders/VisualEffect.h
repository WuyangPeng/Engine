// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:32)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_H
#define RENDERING_SHADERS_VISUAL_EFFECT_H

#include "Rendering/RenderingDll.h"

#include "VisualTechnique.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "CoreTools/Helper/ExportMacro.h"


namespace CoreTools
{
	class WriteFileManager;
	class ReadFileManager;
}

RENDERING_EXPORT_SHARED_PTR(VisualEffectImpl);

namespace Rendering
{
	class RENDERING_DEFAULT_DECLARE VisualEffect : public CoreTools::Object
	{
	public:
            COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualEffect, DESTRUCTOR_STATEMENT);
		using ParentType = Object;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VisualEffect(); 

		CLASS_INVARIANT_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffect);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		 
		// 支持延迟构造。函数追加新的technique到数组的末尾。
		void InsertTechnique(const VisualTechniqueSharedPtr& technique);

		int GetNumTechniques() const;
		const ConstVisualTechniqueSharedPtr GetTechnique(int techniqueIndex) const;

		// 获得的effect的组件。
		int GetNumPasses(int techniqueIndex) const;
		const ConstVisualPassSharedPtr GetPass(int techniqueIndex, int passIndex) const;
		const ConstVertexShaderSharedPtr GetVertexShader(int techniqueIndex, int passIndex) const;
		const ConstPixelShaderSharedPtr GetPixelShader(int techniqueIndex, int passIndex) const;
		const ConstAlphaStateSharedPtr GetAlphaState(int techniqueIndex, int passIndex) const;
		const ConstCullStateSharedPtr GetCullState(int techniqueIndex, int passIndex) const;
		const ConstDepthStateSharedPtr GetDepthState(int techniqueIndex, int passIndex) const;
		const ConstOffsetStateSharedPtr GetOffsetState(int techniqueIndex, int passIndex) const;
		const ConstStencilStateSharedPtr GetStencilState(int techniqueIndex, int passIndex) const;
		const ConstWireStateSharedPtr GetWireState(int techniqueIndex, int passIndex) const;

		void SaveVisualTechnique(WriteFileManager& manager) const;
		void LoadVisualTechnique(ReadFileManager& manager);
                ObjectInterfaceSharedPtr CloneObject() const override;
	private:
		IMPL_TYPE_DECLARE(VisualEffect);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VisualEffect);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SHARED_PTR_DECLARE( VisualEffect); 
}

#endif // RENDERING_SHADERS_VISUAL_EFFECT_H
