// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/24 15:11)

#ifndef RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H
#define RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H

#include "Rendering/Shaders/VisualPass.h"

namespace CoreTools
{
	class BufferTarget;
	class BufferSource;
	class ObjectLink;
	class ObjectRegister;
	class Object;
	class WriteFileManager;
	class ReadFileManager;
}

namespace Rendering
{
	class RENDERING_HIDDEN_DECLARE VisualTechniqueImpl
	{
	public:
		using ClassType = VisualTechniqueImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VisualTechniqueImpl();

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
		
		// 支持延迟构造。函数追加新的pass到数组的末尾。
		void InsertPass (const VisualPassSharedPtr& pass);
		
		int GetNumPasses () const;
		const ConstVisualPassSharedPtr GetPass (int passIndex) const;
		
		// 访问pass的组件。
		const ConstVertexShaderSharedPtr GetVertexShader (int passIndex) const;
		const ConstPixelShaderSharedPtr GetPixelShader (int passIndex) const;
		const ConstAlphaStateSharedPtr GetAlphaState (int passIndex) const;
		const ConstCullStateSharedPtr GetCullState (int passIndex) const;
		const ConstDepthStateSharedPtr GetDepthState (int passIndex) const;
		const ConstOffsetStateSharedPtr GetOffsetState (int passIndex) const;
		const ConstStencilStateSharedPtr GetStencilState (int passIndex) const;
		const ConstWireStateSharedPtr GetWireState (int passIndex) const;

		void SaveVisualPass(WriteFileManager& manager) const;
		void LoadVisualPass(ReadFileManager& manager);

	private:
		std::vector<VisualPassSharedPtr> m_Passes;
	};
}

#endif // RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H
