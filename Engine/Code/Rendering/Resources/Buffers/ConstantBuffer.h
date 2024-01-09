/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 13:48)

#ifndef RENDERING_RESOURCES_CONSTANT_BUFFER_H
#define RENDERING_RESOURCES_CONSTANT_BUFFER_H

#include "Rendering/RenderingDll.h"

#include "Buffer.h"
#include "MemberLayout.h"
#include "Mathematics/Algebra/Matrix.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ConstantBuffer, BufferLayout);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ConstantBuffer : public Buffer
    {
    public:
        using ConstantBufferImpl = BufferLayout;
        COPY_UNSHARED_TYPE_DECLARE(ConstantBuffer);
        using ParentType = Buffer;

        using MemberLayoutContainer = std::vector<MemberLayout>;

    public:
        ConstantBuffer(const std::string& name, int numBytes, bool allowDynamicUpdate);
        ConstantBuffer(const std::string& name, int numBytes, bool allowDynamicUpdate, const MemberLayoutContainer& memberLayoutContainer);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ConstantBuffer);

        void SetLayout(const MemberLayoutContainer& memberLayoutContainer);
        NODISCARD MemberLayoutContainer GetLayout() const;

        NODISCARD bool HasMember(const std::string& name) const;

        NODISCARD MemberLayout GetMember(const std::string& name) const;

        template <typename T>
        void SetMember(const std::string& name, const T& value);

        template <typename T>
        void SetMember(const std::string& name, const Mathematics::Matrix<T>& value);

        template <typename T>
        NODISCARD T GetMember(const std::string& name) const;

        template <typename T>
        NODISCARD Mathematics::Matrix<T> GetMatrixMember(const std::string& name) const;

        template <typename T>
        void SetMember(const std::string& name, int index, const T& value);

        template <typename T>
        NODISCARD T GetMember(const std::string& name, int index) const;

        NODISCARD ObjectInterfaceSharedPtr CloneObject() const override;

        NODISCARD static constexpr auto GetShaderDataLookup() noexcept
        {
            return 0;
        }

        NODISCARD RendererObjectSharedPtr CreateRendererObject(RendererTypes rendererTypes) override;

    protected:
        NODISCARD static int GetRoundedNumBytes(int numBytes) noexcept;

    private:
        static auto constexpr constantBufferRequiredMinimumBytes = 256;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ConstantBuffer);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ConstantBuffer);
}

#endif  // RENDERING_RESOURCES_CONSTANT_BUFFER_H
