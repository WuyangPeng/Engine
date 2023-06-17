///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:01)

#ifndef RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
#define RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AQuaternion.h"
#include "Mathematics/Algebra/Matrix.h"
#include "Rendering/Controllers/ControllerKeyInfo.h"
#include "Rendering/DataTypes/Transform.h"

#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE KeyframeControllerImpl
    {
    public:
        using ClassType = KeyframeControllerImpl;
        using AQuaternion = Mathematics::AQuaternionF;
        using APoint = Mathematics::APointF;
        using Matrix = Mathematics::MatrixF;

    public:
        // ���ƽ�ƣ���ת�����Ŷ�������ͬ�Ĺؼ�֡ʱ�䣬��numCommonTimes������Ϊ������
        // ÿ��ʣ������ΪnumCommonTimes����ͨ�����ڣ���Ϊ��ʱ��
        // ����ؼ�֡ʱ�䲻������numCommonTimes��������Ϊ�㣬������������趨Ϊ�ʵ���ֵ
        // ���ŵ�����ʱΪ��ֵ��������ʽΪ�㡣

        // �任�����ʼ�����ƶ���ľֲ��任��
        // ��������ǰ����Ϊ��Ϊ���ֻ���ɹؼ�֡�����ͨ���任��
        // �������������ռ�Spatial m_Object������Ӧ�ó����ʵ�����������ͨ����
        // ����KeyframeController����*����*��ͨ����
        KeyframeControllerImpl() noexcept;
        KeyframeControllerImpl(int numCommonTimes, int numTranslations, int numRotations, int numScales);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    public:
        // ���ù��캯������������������ʹ����Щ������
        NODISCARD int GetNumCommonTimes() const noexcept;
        NODISCARD float GetCommonTimes(int index) const;
        void SetCommonTimes(int index, float aCommonTimes);

        NODISCARD int GetNumTranslations() const noexcept;
        NODISCARD float GetTranslationTimes(int index) const;
        NODISCARD APoint GetTranslations(int index) const;

        void SetTranslationTimes(int index, float translationTime);
        void SetTranslations(int index, const APoint& translation);

        NODISCARD int GetNumRotations() const noexcept;
        NODISCARD float GetRotationTimes(int index) const;
        NODISCARD AQuaternion GetRotations(int index) const;

        void SetRotationTimes(int index, float rotationTime);
        void SetRotations(int index, const AQuaternion& rotation);

        NODISCARD int GetNumScales() const noexcept;
        NODISCARD float GetScaleTimes(int index) const;
        NODISCARD float GetScales(int index) const;

        void SetScaleTimes(int index, float scaleTime);
        void SetScales(int index, float scale);

        NODISCARD ControllerKeyInfo GetTranslateKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetRotateKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetScaleKeyInfo(float ctrlTime);
        NODISCARD ControllerKeyInfo GetCommonKeyInfo(float ctrlTime);

        NODISCARD APoint GetTranslate(const ControllerKeyInfo& keyInfo) const;
        NODISCARD Matrix GetRotate(const ControllerKeyInfo& keyInfo) const noexcept;
        NODISCARD float GetScale(const ControllerKeyInfo& keyInfo) const noexcept;

    private:
        // ֧�ֲ��Ҹ���ָ��ʱ��Ĺؼ�֡��
        NODISCARD static ControllerKeyInfo GetKeyInfo(float ctrlTime, const std::vector<float>& times, int& lastIndex);

        void ResetArraySize();

    private:
        // times��ƽ�ƣ���ת�ͱ��������������ʱ��ʹ�á�
        int numCommonTimes;
        std::vector<float> commonTimes;

        int numTranslations;
        std::vector<float> translationTimes;
        std::vector<APoint> translations;

        int numRotations;
        std::vector<float> rotationTimes;
        std::vector<AQuaternion> rotations;

        int numScales;
        std::vector<float> scaleTimes;
        std::vector<float> scales;

        // �����ڹ�ȥ�Ĳ��ҵ��ļ���������
        // ����ʱ�����У��Ᵽ֤��O(1) ���ҡ�
        int translationLastIndex;
        int rotationLastIndex;
        int scaleLastIndex;
        int commonLastIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
