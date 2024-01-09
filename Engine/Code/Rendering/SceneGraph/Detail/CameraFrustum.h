/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/28 17:31)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

#include <array>

namespace Rendering
{
    /// Ĭ�ϵ�͸����׶�����90�ȵ���Ұ��1.0�Ŀ�߱ȡ���ֵ1��Զֵ10000��
    /// Ĭ��������ͼ��ͷ���(r,u,d)Ϊ[-1,1]^2 x [0,1]��
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
        using ClassType = CameraFrustum;

        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

        static constexpr auto quantity = System::EnumCastUnderlying(ViewFrustum::Quantity);
        using Container = std::array<float, quantity>;

    public:
        CameraFrustum() noexcept;
        CameraFrustum(bool isPerspective, float epsilon);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsPerspective() const noexcept;

        /// ������ͼƽ��ͷ�塣����[rMin,rMax] �������ҷ���R��
        /// ��Щ������ƽ��ͷ��ġ�left���͡�right��ֵ��
        /// ����[uMin,uMax] �������Ϸ���U��
        /// ��Щ�ǡ�bottom���͡�top��ֵ��
        /// ����[dMin,dMax] ������ͼ����D��
        /// ��Щ�ǡ�near���͡�far��ֵ��
        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax);

        /// ͬʱ������ͼƽ��ͷ�����е�ֵ��
        /// ����������밴dMin, dMax, uMin, uMax, rMin, rMax��˳��
        void SetFrustum(const Container& aFrustum) noexcept;

        /// ����һ���ԳƵ���ͼƽ��ͷ��(uMin = -uMax, rMin = -rMax)
        /// ʹ��һ����ͼ�ֶ���up�����һ����߱ȡ�
        /// ��������൱��OpenGL��gluPerspective��
        /// ��ˣ������������ָ����ͼ�Ķ�����������(0,180)
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax);

        /// ͬʱ���������ͼƽ��ͷ���ֵ��
        NODISCARD Container GetFrustum() const noexcept;

        /// �õ�һ���Գ���ͼƽ��ͷ��Ĳ�����
        /// ���ص�CameraFrustumData����IsSymmetric��true���ҽ���ƽ��ͷ���ǶԳƵģ�
        /// ֻ������������£�����ֵ������Ч�ġ�
        NODISCARD CameraFrustumData GetSymmetricFrustum() const;

        /// ��õ�һ��ͼƽ��ͷ���ֵ��
        NODISCARD float GetDirectionMin() const;
        NODISCARD float GetDirectionMax() const;
        NODISCARD float GetUpMin() const;
        NODISCARD float GetUpMax() const;
        NODISCARD float GetRightMin() const;
        NODISCARD float GetRightMax() const;

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        NODISCARD float& GetFrustum(ViewFrustum viewFrustum);
        NODISCARD float GetFrustum(ViewFrustum viewFrustum) const;

    private:
        /// ��ͼƽ��ͷ��,�洢��˳��ΪdMin (near), dMax (far),uMin (bottom), uMax (top), rMin (left), �� rMax (right)��˳��洢��
        Container frustum;

        /// �����Ա�ǡ�true������͸��������ǡ�false���������������
        bool isPerspective;

        float epsilon;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
