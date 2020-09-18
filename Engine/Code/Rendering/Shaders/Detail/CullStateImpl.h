// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.0.0.3 (2019/07/24 14:32)

#ifndef RENDERING_SHADERS_CULL_STATE_IMPL_H
#define RENDERING_SHADERS_CULL_STATE_IMPL_H

#include "Rendering/RenderingDll.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"

namespace CoreTools
{
    class BufferSource;
    class BufferTarget;
    class WriteFileManager;
    class ReadFileManager;
}

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

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
#endif  // OPEN_CLASS_INVARIANT

        void Load(BufferSource& source);
        void Save(const CoreTools::BufferTargetSharedPtr& target) const;
        int GetStreamingSize() const noexcept;

        bool IsEnabled() const noexcept;
        void SetEnabled(bool enabled) noexcept;
        bool IsCCWOrder() const noexcept;
        void SetCCWOrder(bool cCWOrder) noexcept;

        void SaveState(WriteFileManager& manager) const;
        void LoadState(ReadFileManager& manager);

    private:
        bool m_Enabled;  // ƒ¨»œ: true
        bool m_CCWOrder;  // ƒ¨»œ: true
    };
}

#endif  // RENDERING_SHADERS_CULL_STATE_IMPL_H
