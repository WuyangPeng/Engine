///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 17:12)

#ifndef RENDERING_SHADERS_VISUAL_PASS_IMPL_H
#define RENDERING_SHADERS_VISUAL_PASS_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
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
        VisualPassImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        void SetVertexShader(const VertexShaderSharedPtr& aVertexShader) noexcept;
        void SetPixelShader(const PixelShaderSharedPtr& aPixelShader) noexcept;
        void SetAlphaState(const AlphaStateSharedPtr& aAlphaState) noexcept;
        void SetCullState(const CullStateSharedPtr& aCullState) noexcept;
        void SetDepthState(const DepthStateSharedPtr& aDepthState) noexcept;
        void SetOffsetState(const OffsetStateSharedPtr& aOffsetState) noexcept;
        void SetStencilState(const StencilStateSharedPtr& aStencilState) noexcept;
        void SetWireState(const WireStateSharedPtr& aWireState) noexcept;

        NODISCARD ConstVertexShaderSharedPtr GetVertexShader() const noexcept;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader() const noexcept;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState() const noexcept;
        NODISCARD ConstCullStateSharedPtr GetCullState() const noexcept;
        NODISCARD ConstDepthStateSharedPtr GetDepthState() const noexcept;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState() const noexcept;
        NODISCARD ConstStencilStateSharedPtr GetStencilState() const noexcept;
        NODISCARD ConstWireStateSharedPtr GetWireState() const noexcept;

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
        CoreTools::ObjectAssociated<VertexShader> vertexShader;
        CoreTools::ObjectAssociated<PixelShader> pixelShader;
        CoreTools::ObjectAssociated<AlphaState> alphaState;
        CoreTools::ObjectAssociated<CullState> cullState;
        CoreTools::ObjectAssociated<DepthState> depthState;
        CoreTools::ObjectAssociated<OffsetState> offsetState;
        CoreTools::ObjectAssociated<StencilState> stencilState;
        CoreTools::ObjectAssociated<WireState> wireState;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_PASS_IMPL_H
