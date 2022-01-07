// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 15:10)

#ifndef RENDERING_SHADERS_VISUAL_PASS_IMPL_H
#define RENDERING_SHADERS_VISUAL_PASS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Shaders/AlphaState.h"
#include "Rendering/Shaders/CullState.h"
#include "Rendering/Shaders/DepthState.h"
#include "Rendering/Shaders/OffsetState.h"
#include "Rendering/Shaders/PixelShader.h"
#include "Rendering/Shaders/StencilState.h"
#include "Rendering/Shaders/VertexShader.h"
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
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        void SetVertexShader(const VertexShaderSharedPtr& vertexShader);
        void SetPixelShader(const PixelShaderSharedPtr& pixelShader);
        void SetAlphaState(const AlphaStateSharedPtr& alphaState);
        void SetCullState(const CullStateSharedPtr& cullState);
        void SetDepthState(const DepthStateSharedPtr& depthState);
        void SetOffsetState(const OffsetStateSharedPtr& offsetState);
        void SetStencilState(const StencilStateSharedPtr& stencilState);
        void SetWireState(const WireStateSharedPtr& wireState);

        const ConstVertexShaderSharedPtr GetVertexShader() const;
        const ConstPixelShaderSharedPtr GetPixelShader() const;
        const ConstAlphaStateSharedPtr GetAlphaState() const;
        const ConstCullStateSharedPtr GetCullState() const;
        const ConstDepthStateSharedPtr GetDepthState() const;
        const ConstOffsetStateSharedPtr GetOffsetState() const;
        const ConstStencilStateSharedPtr GetStencilState() const;
        const ConstWireStateSharedPtr GetWireState() const;

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
        VertexShaderSharedPtr m_VertexShader;
        PixelShaderSharedPtr m_PixelShader;
        AlphaStateSharedPtr m_AlphaState;
        CullStateSharedPtr m_CullState;
        DepthStateSharedPtr m_DepthState;
        OffsetStateSharedPtr m_OffsetState;
        StencilStateSharedPtr m_StencilState;
        WireStateSharedPtr m_WireState;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PASS_IMPL_H
