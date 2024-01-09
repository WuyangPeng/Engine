///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:13)

#include "Rendering/RenderingExport.h"

#include "PickerImpl.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/Picking/PickRecord.h"

Rendering::PickerImpl::PickerImpl(int numThreads)
    : numThreads{ 1 < numThreads ? numThreads : 1 }, maxDistance{}, origin{}, direction{}, tMin{}, tMax{}, records{ PickRecordContainer::Create() }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::PickerImpl::IsValid() const noexcept
{
    if (tMin <= tMax)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void Rendering::PickerImpl::SetMaxDistance(float aMaxDistance) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    maxDistance = aMaxDistance;
}

float Rendering::PickerImpl::GetMaxDistance() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return maxDistance;
}

void Rendering::PickerImpl::operator()(Spatial& scene,
                                       const APoint& aOrigin,
                                       const AVector& aDirection,
                                       float aTMin,
                                       float aTMax)
{
    RENDERING_CLASS_IS_VALID_1;

    origin = aOrigin;
    direction = aDirection;
    tMin = aTMin;
    tMax = aTMax;

    records.Clear();
    ExecuteRecursive(scene);
}

bool Rendering::PickerImpl::IsRecordsExist() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return !records.IsEmpty();
}

Rendering::PickRecord Rendering::PickerImpl::GetClosestToZero() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (IsRecordsExist())
    {
        auto closest = Mathematics::MathF::maxReal;
        auto index = -1;
        const auto numRecords = records.GetSize();
        for (auto i = 0; i < numRecords; ++i)
        {
            if (const auto distanceToLinePoint = records.GetPickRecord(i).GetDistanceToLinePoint();
                distanceToLinePoint < closest)
            {
                closest = distanceToLinePoint;
                index = i;
            }
        }

        return records.GetPickRecord(index);
    }

    THROW_EXCEPTION(SYSTEM_TEXT("��¼�����ڣ�"s));
}

Rendering::PickRecord Rendering::PickerImpl::GetClosestNonnegative() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (IsRecordsExist())
    {
        auto closest = Mathematics::MathF::maxReal;

        const auto numRecords = records.GetSize();
        auto findIndex = -1;
        for (auto i = 0; i < numRecords; ++i)
        {
            if (const auto parameter = records.GetPickRecord(i).GetT();
                0.0f <= parameter)
            {
                closest = parameter;
                findIndex = i;
                break;
            }
        }

        if (findIndex == -1)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��¼��ֵ���Ǹ�����"s));
        }

        for (auto i = findIndex + 1; i < numRecords; ++i)
        {
            const auto pickRecord = records.GetPickRecord(i);
            const auto distanceToLinePoint = pickRecord.GetDistanceToLinePoint();
            const auto t = pickRecord.GetT();
            if (0.0f <= t && distanceToLinePoint < closest)
            {
                closest = distanceToLinePoint;
                findIndex = i;
            }
        }

        return records.GetPickRecord(findIndex);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��¼�����ڣ�"s));
    }
}

Rendering::PickRecord Rendering::PickerImpl::GetClosestNonpositive() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (IsRecordsExist())
    {
        auto closest = -Mathematics::MathF::maxReal;

        const auto numRecords = records.GetSize();
        auto findIndex = -1;

        for (auto i = 0; i < numRecords; ++i)
        {
            if (const auto t = records.GetPickRecord(i).GetT();
                t <= 0.0f)
            {
                closest = t;
                findIndex = i;
                break;
            }
        }

        if (closest == -1)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("��¼��ֵ����������"s));
        }

        for (auto i = findIndex + 1; i < numRecords; ++i)
        {
            const auto pickRecord = records.GetPickRecord(i);
            const auto distanceToLinePoint = pickRecord.GetDistanceToLinePoint();
            const auto t = pickRecord.GetT();
            if (t <= 0 && distanceToLinePoint < closest)
            {
                closest = distanceToLinePoint;
                findIndex = i;
            }
        }

        return records.GetPickRecord(findIndex);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��¼�����ڣ�"s));
    }
}

void Rendering::PickerImpl::ExecuteRecursive(Spatial& object)
{
    RENDERING_CLASS_IS_VALID_1;

    records = object.ExecuteRecursive(origin, direction, tMin, tMax, numThreads, maxDistance);
}
