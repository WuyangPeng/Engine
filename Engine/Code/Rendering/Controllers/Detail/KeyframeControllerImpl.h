///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:01)

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
        // 如果平移，旋转和缩放都有着相同的关键帧时间，则numCommonTimes被设置为正数。
        // 每个剩余数量为numCommonTimes，当通道存在，或为零时。
        // 如果关键帧时间不共享，则numCommonTimes必须设置为零，而其余的数字设定为适当的值
        // 当信道存在时为正值和其他方式为零。

        // 变换输入初始化控制对象的局部变换。
        // 这个类的以前的行为是为了填补只能由关键帧代表的通道变换，
        // 其中隐含依靠空间Spatial m_Object有它的应用程序适当地设置其他通道。
        // 现在KeyframeController设置*所有*的通道。
        KeyframeControllerImpl() noexcept;
        KeyframeControllerImpl(int numCommonTimes, int numTranslations, int numRotations, int numScales);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetStreamingSize() const noexcept;
        void Save(CoreTools::BufferTarget& target) const;
        void Load(CoreTools::BufferSource& source);

    public:
        // 调用构造函数后，您必须设置数据使用这些函数。
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
        // 支持查找给出指定时间的关键帧。
        NODISCARD static ControllerKeyInfo GetKeyInfo(float ctrlTime, const std::vector<float>& times, int& lastIndex);

        void ResetArraySize();

    private:
        // times当平移，旋转和比例共享这个数组时才使用。
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

        // 缓存在过去的查找到的键对索引。
        // 对于时间序列，这保证了O(1) 查找。
        int translationLastIndex;
        int rotationLastIndex;
        int scaleLastIndex;
        int commonLastIndex;
    };
}

#endif  // RENDERING_CONTROLLERS_KEYFRAME_CONTROLLER_IMPL_H
