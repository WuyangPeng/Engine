///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.6 (2022/04/11 17:08)

#ifndef RENDERING_SHADERS_CULL_STATE_IMPL_H
#define RENDERING_SHADERS_CULL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/FileManager/FileManagerFwd.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CullStateImpl
    {
    public:
        typedef CullStateImpl ClassType;
        typedef CoreTools::BufferSource BufferSource;
        typedef CoreTools::BufferTarget BufferTarget;
        typedef CoreTools::WriteFileManager WriteFileManager;
        typedef CoreTools::ReadFileManager ReadFileManager;

    public:
        CullStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD bool IsEnabled() const noexcept;
        void SetEnabled(bool aEnabled) noexcept;
        NODISCARD bool IsCCWOrder() const noexcept;
        void SetCCWOrder(bool aCCWOrder) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool enabled;  // Ĭ��: true
        bool ccwOrder;  // Ĭ��: true
    };
}

#endif  // RENDERING_SHADERS_CULL_STATE_IMPL_H
