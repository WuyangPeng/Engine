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
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Rendering/Detail/SwitchNode.h"
#include "Rendering/SceneGraph/PickRecord.h"
#include "Rendering/SceneGraph/TrianglesMesh.h"

Rendering::PickerImpl::PickerImpl(const Spatial& scene, const APoint& origin, const AVector& direction, float tMin, float tMax)
    : origin{ origin }, direction{ direction }, tMin{ tMin }, tMax{ tMax }, records{ PickRecordContainer::Create() }
{
    ExecuteRecursive(scene);

    RENDERING_SELF_CLASS_IS_VALID_1;
}

// private
void Rendering::PickerImpl::ExecuteRecursive(const Spatial& object)
{
    records = object.ExecuteRecursive(origin, direction, tMin, tMax);
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
        auto closest = Mathematics::MathF::FAbs(records.GetPickRecord(0).GetParameter());
        auto index = 0;
        const auto numRecords = records.GetSize();
        for (auto i = 1; i < numRecords; ++i)
        {
            auto parameter = Mathematics::MathF::FAbs(records.GetPickRecord(i).GetParameter());
            if (parameter < closest)
            {
                closest = parameter;
                index = i;
            }
        }
        return records.GetPickRecord(index);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��¼�����ڣ�"s));
    }
}

Rendering::PickRecord Rendering::PickerImpl::GetClosestNonnegative() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (IsRecordsExist())
    {
        // ��ȡ��һ��������
        auto closest = Mathematics::MathF::maxReal;

        const auto numRecords = records.GetSize();
        auto findIndex = -1;
        for (auto i = 0; i < numRecords; ++i)
        {
            const auto parameter = records.GetPickRecord(i).GetParameter();
            if (0.0f <= parameter)
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
            const auto parameter = records.GetPickRecord(i).GetParameter();
            if (0.0f <= parameter && parameter < closest)
            {
                closest = parameter;
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
        // ��ȡ��һ��������
        auto closest = -Mathematics::MathF::maxReal;

        const auto numRecords = records.GetSize();
        auto findIndex = -1;

        for (auto i = 0; i < numRecords; ++i)
        {
            const auto parameter = records.GetPickRecord(i).GetParameter();
            if (parameter <= 0.0f)
            {
                closest = parameter;
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
            const auto parameter = records.GetPickRecord(i).GetParameter();
            if (closest < parameter && parameter <= 0.0f)
            {
                closest = parameter;
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
