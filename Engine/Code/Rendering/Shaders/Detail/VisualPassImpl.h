// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:10)

#ifndef RENDERING_SHADERS_VISUAL_PASS_IMPL_H
#define RENDERING_SHADERS_VISUAL_PASS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/VertexShader.h"
#include "Rendering/Shaders/PixelShader.h"
#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/WireState.h"

#include <string>
#include <vector>

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
	class RENDERING_HIDDEN_DECLARE VisualPassImpl
	{
	public:
		using ClassType = VisualPassImpl;
		using Object = CoreTools::Object;
		using BufferTarget = CoreTools::BufferTarget;
		using BufferSource = CoreTools::BufferSource;
		using ObjectLink = CoreTools::ObjectLink;
		using ObjectRegister = CoreTools::ObjectRegister;
		using WriteFileManager = CoreTools::WriteFileManager;
		using ReadFileManager = CoreTools::ReadFileManager;

	public:
		VisualPassImpl();

		CLASS_INVARIANT_DECLARE;

		int GetStreamingSize() const;
		void Save(const CoreTools::BufferTargetSharedPtr& target) const;
		void Load(BufferSource& source);
		void Link(ObjectLink& source);
                void Register(const CoreTools::ObjectRegisterSharedPtr& target) const;

		CORE_TOOLS_NAMES_IMPL_DECLARE;

		void SetVertexShader(const VertexShaderSmartPointer& vertexShader);
		void SetPixelShader(const PixelShaderSmartPointer& pixelShader);
		void SetAlphaState(const AlphaStateSmartPointer& alphaState);
		void SetCullState(const CullStateSmartPointer& cullState);
		void SetDepthState(const DepthStateSmartPointer& depthState);
		void SetOffsetState(const OffsetStateSmartPointer& offsetState);
		void SetStencilState(const StencilStateSmartPointer& stencilState);
		void SetWireState(const WireStateSmartPointer& wireState);
     
		const ConstVertexShaderSmartPointer GetVertexShader() const;
		const ConstPixelShaderSmartPointer GetPixelShader() const;
		const ConstAlphaStateSmartPointer GetAlphaState() const;
		const ConstCullStateSmartPointer GetCullState() const;
		const ConstDepthStateSmartPointer GetDepthState() const;
		const ConstOffsetStateSmartPointer GetOffsetState() const;
		const ConstStencilStateSmartPointer GetStencilState() const;
		const ConstWireStateSmartPointer GetWireState() const;

		void SaveShader(WriteFileManager& manager) const;
		void SaveState(WriteFileManager& manager) const;
		void LoadShader(ReadFileManager& manager);
		void LoadState(ReadFileManager& manager);

	private:
		void LoadVertexShader(ReadFileManager& manager);
		void LoadPixelShader(ReadFileManager& manager);
		void LoadAlphaState(ReadFileManager& manager);
		void LoadCullState(ReadFileManager& manager);
		void LoadDepthState(ReadFileManager& manager);
		void LoadOffsetState(ReadFileManager& manager);
		void LoadStencilState(ReadFileManager& manager);
		void LoadWireState(ReadFileManager& manager);

	private:
		VertexShaderSmartPointer m_VertexShader;
		PixelShaderSmartPointer m_PixelShader;
		AlphaStateSmartPointer m_AlphaState;
		CullStateSmartPointer m_CullState;
		DepthStateSmartPointer m_DepthState;
		OffsetStateSmartPointer m_OffsetState;
		StencilStateSmartPointer m_StencilState;
		WireStateSmartPointer m_WireState;
	};
}

#endif // RENDERING_SHADERS_VISUAL_PASS_IMPL_H
