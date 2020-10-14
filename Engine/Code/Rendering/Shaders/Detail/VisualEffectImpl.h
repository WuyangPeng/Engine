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
		void Load(const CoreTools::BufferSourceSharedPtr& source);
		void Link(const CoreTools:: ObjectLinkSharedPtr& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;

		// ֧���ӳٹ��졣����׷���µ�technique�������ĩβ��
		void InsertTechnique(const VisualTechniqueSharedPtr& technique);

		int GetNumTechniques() const;
		const ConstVisualTechniqueSharedPtr GetTechnique(int techniqueIndex) const;

		// ��õ�effect�������
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

	private:
		std::vector<VisualTechniqueSharedPtr> m_Techniques;
	};
}

#endif // RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
