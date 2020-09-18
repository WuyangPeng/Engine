// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/24 15:03)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H

#include "Rendering/Shaders/VisualTechnique.h"

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
	class RENDERING_HIDDEN_DECLARE VisualEffectImpl
	{
	public:
		using ClassType = VisualEffectImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VisualEffectImpl();

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		void Load(BufferSource& source);
		void Link(ObjectLink& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;

		// ֧���ӳٹ��졣����׷���µ�technique�������ĩβ��
		void InsertTechnique(const VisualTechniqueSmartPointer& technique);

		int GetNumTechniques() const;
		const ConstVisualTechniqueSmartPointer GetTechnique(int techniqueIndex) const;

		// ��õ�effect�������
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
		std::vector<VisualTechniqueSmartPointer> m_Techniques;
	};
}

#endif // RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
