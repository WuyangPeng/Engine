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
		void Save(BufferTarget& target) const;
		void Load(BufferSource& source);
		void Link(ObjectLink& source);
		void Register(ObjectRegister& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;
		
		// 支持延迟构造。函数追加新的pass到数组的末尾。
		void InsertPass (const VisualPassSmartPointer& pass);
		
		int GetNumPasses () const;
		const ConstVisualPassSmartPointer GetPass (int passIndex) const;
		
		// 访问pass的组件。
		const ConstVertexShaderSmartPointer GetVertexShader (int passIndex) const;
		const ConstPixelShaderSmartPointer GetPixelShader (int passIndex) const;
		const ConstAlphaStateSmartPointer GetAlphaState (int passIndex) const;
		const ConstCullStateSmartPointer GetCullState (int passIndex) const;
		const ConstDepthStateSmartPointer GetDepthState (int passIndex) const;
		const ConstOffsetStateSmartPointer GetOffsetState (int passIndex) const;
		const ConstStencilStateSmartPointer GetStencilState (int passIndex) const;
		const ConstWireStateSmartPointer GetWireState (int passIndex) const;

		void SaveVisualPass(WriteFileManager& manager) const;
		void LoadVisualPass(ReadFileManager& manager);

	private:
		std::vector<VisualPassSmartPointer> m_Passes;
	};
}

#endif // RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H
