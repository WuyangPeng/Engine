///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/13 14:19)

#ifndef FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H
#define FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H

#include "Framework/FrameworkDll.h"

#include "Framework/Application/PerformanceMeasurements.h"

namespace Framework
{
    class FRAMEWORK_HIDDEN_DECLARE ModelMiddleLayerImpl
    {
    public:
        using ClassType = ModelMiddleLayerImpl;

    public:
        explicit ModelMiddleLayerImpl(int maxTimer);

        CLASS_INVARIANT_DECLARE;

        NODISCARD double GetFrameRate() const;
        NODISCARD std::string GetFrameRateMessage() const;

        void ResetTime();
        void MeasureTime();
        void UpdateFrameCount();

    private:
        PerformanceMeasurements performanceMeasurements;
    };
}

#endif  // FRAMEWORK_MIDDLE_LAYER_MODEL_MIDDLE_LAYER_IMPL_H
