///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:06)

#ifndef RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
#define RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H

#include "Rendering/RenderingDll.h"

#include "System/Helper/EnumCast.h"
#include "CoreTools/ObjectSystems/BufferTarget.h"
#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/SceneGraph/CameraFrustumData.h"
#include "Rendering/SceneGraph/Flags/CameraFlags.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE CameraFrustum
    {
    public:
        using ClassType = CameraFrustum;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        explicit CameraFrustum(bool isPerspective) noexcept;

        CLASS_INVARIANT_DECLARE;

        // Ĭ����ͼƽ��ͷ����һ��90�ȵ���Ұ,
        // ��߱�Ϊ1����ֵΪ1��ԶֵΪ10000��
        NODISCARD bool IsPerspective() const noexcept;

        // ������ͼƽ��ͷ�塣����[rmin,rmax] �������ҷ���R��
        // ��Щ������ƽ��ͷ��ġ�left���͡�right��ֵ��
        // ����[umin,umax] �������Ϸ���U��
        // ��Щ�ǡ�bottom���͡�top��ֵ��
        // ����[dmin,dmax] ������ͼ����D��
        // ��Щ�ǡ�near���͡�far��ֵ��
        void SetFrustum(float directionMin, float directionMax, float upMin, float upMax, float rightMin, float rightMax) noexcept;

        // ͬʱ������ͼƽ��ͷ�����е�ֵ��
        // ����������밴dmin, dmax, umin, umax, rmin, rmax��˳��
        void SetFrustum(const float* aFrustum) noexcept;

        // ����һ���ԳƵ���ͼƽ��ͷ��(umin = -umax, rmin = -rmax)
        // ʹ��һ����ͼ�ֶ���up�����һ����߱ȡ�
        // ��������൱��OpenGL��gluPerspective��
        // ��ˣ������������ָ����ͼ�Ķ�����������(0,180)
        void SetFrustum(float upFieldOfViewDegrees, float aspectRatio, float directionMin, float directionMax) noexcept;

        // ͬʱ���������ͼƽ��ͷ���ֵ��
        NODISCARD const float* GetFrustum() const noexcept;

        // �õ�һ���Գ���ͼƽ��ͷ��Ĳ�����
        // ����ֵ��true���ҽ���ƽ��ͷ���ǶԳƵģ�
        // ֻ������������£��������������Ч�ġ�
        NODISCARD CameraFrustumData GetFrustumData() const noexcept;

        // ��õ�һ��ͼƽ��ͷ���ֵ��
        NODISCARD float GetDirectionMin() const noexcept;
        NODISCARD float GetDirectionMax() const noexcept;
        NODISCARD float GetUpMin() const noexcept;
        NODISCARD float GetUpMax() const noexcept;
        NODISCARD float GetRightMin() const noexcept;
        NODISCARD float GetRightMax() const noexcept;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        // ��ͼƽ��ͷ��,�洢��˳��Ϊmin (near), dmax (far),
        // umin (bottom), umax (top), rmin (left), �� rmax (right).
        std::array<float, System::EnumCastUnderlying(ViewFrustum::Quantity)> frustum;

        // �����Ա�ǡ�true������͸��������ǡ�false���������������
        bool isPerspective;
    };
}

#endif  // RENDERING_SCENE_GRAPH_CAMERA_FRUSTUM_H
