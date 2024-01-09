/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:33)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
#define RENDERING_SCENE_GRAPH_CAMERA_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CameraMatrix.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/SceneGraph/ViewVolume.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraImpl
    {
    public:
        using ClassType = CameraImpl;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        using Math = Mathematics::MathF;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Matrix = Mathematics::MatrixF;

    public:
        explicit CameraImpl(float epsilon = Mathematics::MathF::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        void SetPreViewMatrix(const Matrix& preViewMatrix);
        NODISCARD Matrix GetPreViewMatrix() const noexcept;
        NODISCARD bool PreViewIsIdentity() const noexcept;

        void SetPostProjectionMatrix(const Matrix& postProjMatrix);
        NODISCARD Matrix GetPostProjectionMatrix() const noexcept;
        NODISCARD bool PostProjectionIsIdentity() const noexcept;

        NODISCARD Matrix GetProjectionViewMatrix(const Matrix& projectionViewMatrix) noexcept;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD float GetEpsilon() const noexcept;

    private:
        CameraMatrix cameraMatrix;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_IMPL_H
