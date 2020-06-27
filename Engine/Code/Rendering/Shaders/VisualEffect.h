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
#include "CoreTools/Helper/SubclassSmartPointerMacro.h"

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
		COPY_UNSHARE_CLASSES_TYPE_DECLARE(VisualEffect);
		using ParentType = Object;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VisualEffect();
		virtual ~VisualEffect();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;
		
		CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(VisualEffect);
		CORE_TOOLS_NAMES_OVERRIDE_DECLARE;
		 
		// 支持延迟构造。函数追加新的technique到数组的末尾。
		void InsertTechnique(const VisualTechniqueSmartPointer& technique);

		int GetNumTechniques() const;
		const ConstVisualTechniqueSmartPointer GetTechnique(int techniqueIndex) const;

		// 获得的effect的组件。
		int GetNumPasses(int techniqueIndex) const;
		const ConstVisualPassSmartPointer GetPass(int techniqueIndex, int passIndex) const;
		const ConstVertexShaderSmartPointer GetVertexShader(int techniqueIndex, int passIndex) const;
		const ConstPixelShaderSmartPointer GetPixelShader(int techniqueIndex, int passIndex) const;
		const ConstAlphaStateSmartPointer GetAlphaState(int techniqueIndex, int passIndex) const;
		const ConstCullStateSmartPointer GetCullState(int techniqueIndex, int passIndex) const;
		const ConstDepthStateSmartPointer GetDepthState(int techniqueIndex, int passIndex) const;
		const ConstOffsetStateSmartPointer GetOffsetState(int techniqueIndex, int passIndex) const;
		const ConstStencilStateSmartPointer GetStencilState(int techniqueIndex, int passIndex) const;
		const ConstWireStateSmartPointer GetWireState(int techniqueIndex, int passIndex) const;

		void SaveVisualTechnique(WriteFileManager& manager) const;
		void LoadVisualTechnique(ReadFileManager& manager);

	private:
		IMPL_TYPE_DECLARE(VisualEffect);
	};
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426) 
	CORE_TOOLS_STREAM_REGISTER(VisualEffect);
#include STSTEM_WARNING_POP
	CORE_TOOLS_SUBCLASS_SMART_POINTER_DECLARE(Third, VisualEffect); 
}

#endif // RENDERING_SHADERS_VISUAL_EFFECT_H
