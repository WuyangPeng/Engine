///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/12 16:02)

#ifndef RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
#define RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/VisualTechnique.h"

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
        VisualEffectImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        // 支持延迟构造。函数追加新的technique到数组的末尾。
        void InsertTechnique(const VisualTechniqueSharedPtr& technique);

        NODISCARD int GetNumTechniques() const;
        NODISCARD ConstVisualTechniqueSharedPtr GetTechnique(int techniqueIndex) const;

        // 获得的effect的组件。
        NODISCARD int GetNumPasses(int techniqueIndex) const;
        NODISCARD ConstVisualPassSharedPtr GetPass(int techniqueIndex, int passIndex) const;
        NODISCARD ConstVertexShaderSharedPtr GetVertexShader(int techniqueIndex, int passIndex) const;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader(int techniqueIndex, int passIndex) const;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstCullStateSharedPtr GetCullState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstDepthStateSharedPtr GetDepthState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstStencilStateSharedPtr GetStencilState(int techniqueIndex, int passIndex) const;
        NODISCARD ConstWireStateSharedPtr GetWireState(int techniqueIndex, int passIndex) const;

        void SaveVisualTechnique(WriteFileManager& manager) const;
        void LoadVisualTechnique(ReadFileManager& manager);

    private:
        std::vector<CoreTools::ObjectAssociated<VisualTechnique>> techniques;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_EFFECT_IMPL_H
