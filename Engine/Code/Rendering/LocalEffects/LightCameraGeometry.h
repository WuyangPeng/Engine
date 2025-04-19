/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 09:48)

#ifndef RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_H
#define RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(LightCameraGeometry, LightCameraGeometryImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE LightCameraGeometry
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(LightCameraGeometry);

        using ColourType = Colour<float>;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using LightCameraGeometrySharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static LightCameraGeometrySharedPtr Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        NODISCARD ColourType GetLightModelPosition() const noexcept;
        void SetLightModelPosition(const ColourType& lightModelPosition) noexcept;
        NODISCARD ColourType GetLightModelDirection() const noexcept;
        void SetLightModelDirection(const ColourType& lightModelDirection) noexcept;
        NODISCARD ColourType GetLightModelUp() const noexcept;
        void SetLightModelUp(const ColourType& lightModelUp) noexcept;
        NODISCARD ColourType GetLightModelRight() const noexcept;
        void SetLightModelRight(const ColourType& lightModelRight) noexcept;
        NODISCARD ColourType GetCameraModelPosition() const noexcept;
        void SetCameraModelPosition(const ColourType& cameraModelPosition) noexcept;
        NODISCARD ColourType GetCameraModelDirection() const noexcept;
        void SetCameraModelDirection(const ColourType& cameraModelDirection) noexcept;
        NODISCARD ColourType GetCameraModelUp() const noexcept;
        void SetCameraModelUp(const ColourType& cameraModelUp) noexcept;
        NODISCARD ColourType GetCameraModelRight() const noexcept;
        void SetCameraModelRight(const ColourType& cameraModelRight) noexcept;

    private:
        enum class LightCameraGeometryCreate
        {
            Init,
        };

    public:
        explicit LightCameraGeometry(LightCameraGeometryCreate lightCameraGeometryCreate);

    private:
        PackageType impl;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_LIGHT_CAMERA_GEOMETRY_H
