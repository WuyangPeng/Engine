///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 11:16)

#include "Framework/FrameworkExport.h"

#include "ModelMiddleLayerImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

using std::string;

Framework::ModelMiddleLayerImpl::ModelMiddleLayerImpl(int maxTimer)
    : performanceMeasurements{ maxTimer }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Framework, ModelMiddleLayerImpl)

double Framework::ModelMiddleLayerImpl::GetFrameRate() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return performanceMeasurements.GetFrameRate();
}

string Framework::ModelMiddleLayerImpl::GetFrameRateMessage() const
{
    FRAMEWORK_CLASS_IS_VALID_CONST_9;

    return performanceMeasurements.GetFrameRateMessage();
}

void Framework::ModelMiddleLayerImpl::ResetTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    performanceMeasurements.ResetTime();
}

void Framework::ModelMiddleLayerImpl::MeasureTime()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    performanceMeasurements.MeasureTime();
}

void Framework::ModelMiddleLayerImpl::UpdateFrameCount()
{
    FRAMEWORK_CLASS_IS_VALID_9;

    performanceMeasurements.UpdateFrameCount();
}
