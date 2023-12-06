///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.1 (2023/11/21 18:11)

#ifndef RENDERING_SCENE_GRAPH_VIEW_VOLUME_H
#define RENDERING_SCENE_GRAPH_VIEW_VOLUME_H

#include "Rendering/RenderingDll.h"

#include "SceneGraphFwd.h"
#include "Flags/CameraFlags.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/Export/CopyUnsharedMacro.h"
#include "CoreTools/ObjectSystems/Object.h"
#include "Mathematics/Algebra/Matrix.h"

RENDERING_COPY_UNSHARED_EXPORT_IMPL(ViewVolume, ViewVolumeImpl);

namespace Rendering
{
    class RENDERING_DEFAULT_DECLARE ViewVolume : public CoreTools::Object
    {
    public:
        COPY_UNSHARED_TYPE_DECLARE(ViewVolume);
        using ParentType = Object;

        using Math = Mathematics::Math<float>;
        using APoint = Mathematics::APoint<float>;
        using AVector = Mathematics::AVector<float>;
        using Matrix = Mathematics::Matrix<float>;

        using Container = std::array<float, System::EnumCastUnderlying(ViewFrustum::Quantity)>;

    public:
        ViewVolume(bool isPerspective, DepthType depthType, float epsilon);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_DEFAULT_OBJECT_STREAM_OVERRIDE_DECLARE(ViewVolume);

        void SetPosition(const APoint& position);
        void SetAxes(const AVector& directionVector, const AVector& upVector, const AVector& rightVector);
        void SetFrame(const APoint& position, const AVector& directionVector, const AVector& upVector, const AVector& rightVector);

        NODISCARD APoint GetPosition() const noexcept;
        NODISCARD AVector GetDirectionVector() const noexcept;
        NODISCARD AVector GetUpVector() const noexcept;
        NODISCARD AVector GetRightVector() const noexcept;

        NODISCARD Matrix GetViewMatrix() const noexcept;
        NODISCARD Matrix GetInverseViewMatrix() const noexcept;

        NODISCARD Matrix GetProjectionMatrix() const noexcept;
        void SetProjectionMatrix(const Matrix& projectionMatrix) noexcept;
        NODISCARD Matrix GetProjectionViewMatrix() const noexcept;
        void SetProjectionViewMatrix(const Matrix& projectionMatrix) noexcept;

        NODISCARD DepthType GetDepthType() const noexcept;

        NODISCARD bool IsPerspective() const noexcept;

        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax);
        void SetFrustum(const Container& frustum);
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax);
        NODISCARD Container GetFrustum() const noexcept;
        NODISCARD CameraFrustumData GetSymmetricFrustum() const;

        NODISCARD float GetDirectionMin() const;
        NODISCARD float GetDirectionMax() const;
        NODISCARD float GetUpMin() const;
        NODISCARD float GetUpMax() const;
        NODISCARD float GetRightMin() const;
        NODISCARD float GetRightMax() const;

    protected:
        virtual void UpdateProjectionViewMatrix() noexcept;

    private:
        PackageType impl;
    };

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

    CORE_TOOLS_INITIALIZE_TERMINATE_REGISTER(ViewVolume);

#include SYSTEM_WARNING_POP

    CORE_TOOLS_SHARED_PTR_DECLARE(ViewVolume);
}

#endif  // RENDERING_SCENE_GRAPH_VIEW_VOLUME_H
