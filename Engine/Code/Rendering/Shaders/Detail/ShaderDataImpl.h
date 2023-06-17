///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 10:30)

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

    public:
        ShaderDataImpl(GraphicsObjectType inType, const std::string& inName, int inBindPoint, int inNumBytes, int inExtra, bool inIsGpuWritable);

        ~ShaderDataImpl() noexcept = default;
        ShaderDataImpl(const ShaderDataImpl& rhs);
        ShaderDataImpl& operator=(const ShaderDataImpl& rhs);
        ShaderDataImpl(ShaderDataImpl&& rhs) noexcept;
        ShaderDataImpl& operator=(ShaderDataImpl&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD GraphicsObjectType GetType() const noexcept;

        NODISCARD std::string GetName() const;
        NODISCARD int GetBindPoint() const noexcept;
        NODISCARD int GetNumBytes() const noexcept;
        NODISCARD int GetExtra() const noexcept;
        NODISCARD bool IsGpuWritable() const noexcept;

        void SetObject(const GraphicsObjectSharedPtr& graphicsObject) noexcept;
        NODISCARD ConstGraphicsObjectSharedPtr GetGraphicsObject() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const;
        void Link(CoreTools::ObjectLink& source);
        void Register(CoreTools::ObjectRegister& target) const;

    private:
        using GraphicsObjectObjectAssociated = CoreTools::ObjectAssociated<GraphicsObject>;

    private:
        GraphicsObjectObjectAssociated object;

        GraphicsObjectType type;

        std::string name;
        int bindPoint;
        int numBytes;
        int extra;
        bool isGpuWritable;
    };
}

#endif  // RENDERING_SHADERS_SHADER_DATA_IMPL_H
