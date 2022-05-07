///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 18:20)

#ifndef RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H
#define RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Shaders/VisualPass.h"

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
        VisualTechniqueImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

        CORE_TOOLS_NAMES_IMPL_DECLARE;

        // ֧���ӳٹ��졣����׷���µ�pass�������ĩβ��
        void InsertPass(const VisualPassSharedPtr& pass);

        NODISCARD int GetNumPasses() const;
        NODISCARD ConstVisualPassSharedPtr GetPass(int passIndex) const;

        // ����pass�������
        NODISCARD ConstVertexShaderSharedPtr GetVertexShader(int passIndex) const;
        NODISCARD ConstPixelShaderSharedPtr GetPixelShader(int passIndex) const;
        NODISCARD ConstAlphaStateSharedPtr GetAlphaState(int passIndex) const;
        NODISCARD ConstCullStateSharedPtr GetCullState(int passIndex) const;
        NODISCARD ConstDepthStateSharedPtr GetDepthState(int passIndex) const;
        NODISCARD ConstOffsetStateSharedPtr GetOffsetState(int passIndex) const;
        NODISCARD ConstStencilStateSharedPtr GetStencilState(int passIndex) const;
        NODISCARD ConstWireStateSharedPtr GetWireState(int passIndex) const;

        void SaveVisualPass(WriteFileManager& manager) const;
        void LoadVisualPass(ReadFileManager& manager);

    private:
        std::vector<CoreTools::ObjectAssociated<VisualPass>> passes;
    };
}

#endif  // RENDERING_SHADERS_VISUAL_TECHNIQUE_IMPL_H
