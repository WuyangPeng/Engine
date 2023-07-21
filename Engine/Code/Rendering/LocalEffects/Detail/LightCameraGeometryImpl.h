///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 10:02)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_IMPL_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE LightCameraGeometryImpl
    {
    public:
        using ClassType = LightCameraGeometryImpl;
        using Colour = Colour<float>;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

    public:
        LightCameraGeometryImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        NODISCARD Colour GetLightModelPosition() const noexcept;
        void SetLightModelPosition(const Colour& aLightModelPosition) noexcept;
        NODISCARD Colour GetLightModelDirection() const noexcept;
        void SetLightModelDirection(const Colour& aLightModelDirection) noexcept;
        NODISCARD Colour GetLightModelUp() const noexcept;
        void SetLightModelUp(const Colour& aLightModelUp) noexcept;
        NODISCARD Colour GetLightModelRight() const noexcept;
        void SetLightModelRight(const Colour& aLightModelRight) noexcept;
        NODISCARD Colour GetCameraModelPosition() const noexcept;
        void SetCameraModelPosition(const Colour& aCameraModelPosition) noexcept;
        NODISCARD Colour GetCameraModelDirection() const noexcept;
        void SetCameraModelDirection(const Colour& aCameraModelDirection) noexcept;
        NODISCARD Colour GetCameraModelUp() const noexcept;
        void SetCameraModelUp(const Colour& aCameraModelUp) noexcept;
        NODISCARD Colour GetCameraModelRight() const noexcept;
        void SetCameraModelRight(const Colour& aCameraModelRight) noexcept;

    private:
        Colour lightModelPosition;  // 默认: (0, 0, 0, 1)
        Colour lightModelDirection;  // 默认: (0, 0, -1, 0)
        Colour lightModelUp;  // 默认: (0, 1, 0, 0)
        Colour lightModelRight;  // 默认: (1, 0, 0, 0)

        Colour cameraModelPosition;  // 默认: (0, 0, 0, 1)
        Colour cameraModelDirection;  // 默认: (0, 0, -1, 0)
        Colour cameraModelUp;  // 默认: (0, 1, 0, 0)
        Colour cameraModelRight;  // 默认: (1, 0, 0, 0)
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_IMPL_H
