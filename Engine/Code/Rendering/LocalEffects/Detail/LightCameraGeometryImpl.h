/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:47)

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

        using ColourType = Colour<float>;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;

    public:
        LightCameraGeometryImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        NODISCARD ColourType GetLightModelPosition() const noexcept;
        void SetLightModelPosition(const ColourType& aLightModelPosition) noexcept;
        NODISCARD ColourType GetLightModelDirection() const noexcept;
        void SetLightModelDirection(const ColourType& aLightModelDirection) noexcept;
        NODISCARD ColourType GetLightModelUp() const noexcept;
        void SetLightModelUp(const ColourType& aLightModelUp) noexcept;
        NODISCARD ColourType GetLightModelRight() const noexcept;
        void SetLightModelRight(const ColourType& aLightModelRight) noexcept;
        NODISCARD ColourType GetCameraModelPosition() const noexcept;
        void SetCameraModelPosition(const ColourType& aCameraModelPosition) noexcept;
        NODISCARD ColourType GetCameraModelDirection() const noexcept;
        void SetCameraModelDirection(const ColourType& aCameraModelDirection) noexcept;
        NODISCARD ColourType GetCameraModelUp() const noexcept;
        void SetCameraModelUp(const ColourType& aCameraModelUp) noexcept;
        NODISCARD ColourType GetCameraModelRight() const noexcept;
        void SetCameraModelRight(const ColourType& aCameraModelRight) noexcept;

    private:
        ColourType lightModelPosition;  // 默认: (0, 0, 0, 1)
        ColourType lightModelDirection;  // 默认: (0, 0, -1, 0)
        ColourType lightModelUp;  // 默认: (0, 1, 0, 0)
        ColourType lightModelRight;  // 默认: (1, 0, 0, 0)

        ColourType cameraModelPosition;  // 默认: (0, 0, 0, 1)
        ColourType cameraModelDirection;  // 默认: (0, 0, -1, 0)
        ColourType cameraModelUp;  // 默认: (0, 1, 0, 0)
        ColourType cameraModelRight;  // 默认: (1, 0, 0, 0)
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_IMPL_H
