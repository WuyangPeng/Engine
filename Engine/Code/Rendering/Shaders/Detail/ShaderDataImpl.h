/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:01)

#ifndef RENDERING_SHADERS_SHADER_DATA_IMPL_H
#define RENDERING_SHADERS_SHADER_DATA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectAssociated.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/Base/BaseFwd.h"
#include "Rendering/Base/GraphicsObject.h"

#include <string>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE ShaderDataImpl
    {
    public:
        using ClassType = ShaderDataImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;
        using ObjectLink = CoreTools::ObjectLink;
        using ObjectRegister = CoreTools::ObjectRegister;

    public:
        ShaderDataImpl(GraphicsObjectType inType, std::string inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable) noexcept;

        ~ShaderDataImpl() noexcept = default;
        ShaderDataImpl(const ShaderDataImpl& rhs);
        ShaderDataImpl& operator=(const ShaderDataImpl& rhs);
        ShaderDataImpl(ShaderDataImpl&& rhs) noexcept;
        ShaderDataImpl& operator=(ShaderDataImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;
        CORE_TOOLS_NAMES_IMPL_DECLARE;

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD std::string GetName() const;
        NODISCARD int GetBindPoint() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;
        NODISCARD int GetExtra() const noexcept;
        NODISCARD bool IsGpuWritable() const noexcept;

        void SetGraphicsObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept;
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const noexcept;
        NODISCARD GraphicsObjectSharedPtr GetGraphicsObject() noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Link(ObjectLink& source);
        void Register(ObjectRegister& target) const;

    private:
        using GraphicsObjectObjectAssociated = CoreTools::ObjectAssociated<GraphicsObject>;

    private:
        GraphicsObjectObjectAssociated object;
        GraphicsObjectType type;
        std::string shaderName;
        int bindPoint;
        int numBytes;
        int extra;
        bool isGpuWritable;
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_IMPL_H
