///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/12 18:40)

#ifndef RENDERING_SHADERS_WIRE_STATE_IMPL_H
#define RENDERING_SHADERS_WIRE_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE WireStateImpl
    {
    public:
        using ClassType = WireStateImpl;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using WriteFileManager = CoreTools::WriteFileManager;
        using ReadFileManager = CoreTools::ReadFileManager;

    public:
        WireStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsEnabled() const noexcept;
        void SetEnabled(bool aEnabled) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool enabled;  // Ĭ��: false
    };
}

#endif  // RENDERING_SHADERS_WIRE_STATE_IMPL_H
