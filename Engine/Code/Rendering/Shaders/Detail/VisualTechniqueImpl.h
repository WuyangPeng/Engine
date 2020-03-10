// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:11)

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
		
		// ֧���ӳٹ��졣����׷���µ�pass�������ĩβ��
		void InsertPass (const VisualPassSmartPointer& pass);
		
		int GetNumPasses () const;
		const ConstVisualPassSmartPointer GetPass (int passIndex) const;
		
		// ����pass�������
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
