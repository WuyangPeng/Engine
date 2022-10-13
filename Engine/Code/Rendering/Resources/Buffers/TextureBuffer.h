///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.0 (2022/08/04 11:54)

#ifndef RENDERING_RENDERERS_TEXTURE_BUFFER_H
#define RENDERING_RENDERERS_TEXTURE_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "MemberLayout.h"
#include "CoreTools/Helper/ExportMacro.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(TextureBuffer, BufferLayout);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE TextureBuffer : public Buffer
    {
    public:
        using TextureBufferImpl = BufferLayout;
        COPY_UNSHARED_TYPE_DECLARE(TextureBuffer);
        using ParentType = Buffer;
        using MemberLayoutContainer = std::vector<MemberLayout>;

    public:
        TextureBuffer(DataFormatType format, int numElements, bool allowDynamicUpdate, const MemberLayoutContainer& memberLayoutContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(TextureBuffer);

        NODISCARD DataFormatType GetFormat() const noexcept;

        void SetLayout(const MemberLayoutContainer& memberLayoutContainer);
        NODISCARD MemberLayoutContainer GetLayout() const;

        NODISCARD bool HasMember(const std::string& name) const;

        NODISCARD MemberLayout GetMember(const std::string& name) const;

        template <typename T>
        void SetMember(const std::string& name, const T& value);

        template <typename T>
        NODISCARD T GetMember(const std::string& name) const;

        template <typename T>
        void SetMember(const std::string& name, int index, const T& value);

        template <typename T>
        NODISCARD T GetMember(const std::string& name, int index) const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 1;
        }

    private:
        PackageType impl;
        DataFormatType format;
    };
}

#endif  // RENDERING_RENDERERS_TEXTURE_BUFFER_H
