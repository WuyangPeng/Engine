///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/06 10:03)

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

        using Colour = Colour<float>;
        using BufferTarget = CoreTools::BufferTarget;
        using BufferSource = CoreTools::BufferSource;
        using LightCameraGeometrySharedPtr = std::shared_ptr<ClassType>;

    public:
        NODISCARD static LightCameraGeometrySharedPtr Create();

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(BufferTarget& target) const;
        void Load(BufferSource& source);

        NODISCARD Colour GetLightModelPosition() const noexcept;
        void SetLightModelPosition(const Colour& lightModelPosition) noexcept;
        NODISCARD Colour GetLightModelDirection() const noexcept;
        void SetLightModelDirection(const Colour& lightModelDirection) noexcept;
        NODISCARD Colour GetLightModelUp() const noexcept;
        void SetLightModelUp(const Colour& lightModelUp) noexcept;
        NODISCARD Colour GetLightModelRight() const noexcept;
        void SetLightModelRight(const Colour& lightModelRight) noexcept;
        NODISCARD Colour GetCameraModelPosition() const noexcept;
        void SetCameraModelPosition(const Colour& cameraModelPosition) noexcept;
        NODISCARD Colour GetCameraModelDirection() const noexcept;
        void SetCameraModelDirection(const Colour& cameraModelDirection) noexcept;
        NODISCARD Colour GetCameraModelUp() const noexcept;
        void SetCameraModelUp(const Colour& cameraModelUp) noexcept;
        NODISCARD Colour GetCameraModelRight() const noexcept;
        void SetCameraModelRight(const Colour& cameraModelRight) noexcept;

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
