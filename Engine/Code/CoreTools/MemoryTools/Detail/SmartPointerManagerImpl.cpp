//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/20 10:04)

#include "CoreTools/CoreToolsExport.h"

#include "SmartPointerManagerImpl.h"
#include "CoreTools/Helper/Assertion/CoreToolsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

CoreTools::SmartPointerManagerImpl::SmartPointerManagerImpl(MAYBE_UNUSED int count) noexcept
    : m_ReferenceContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_3;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::SmartPointerManagerImpl::IsValid() const noexcept
{
    try
    {
        for (const auto& value : m_ReferenceContainer)
        {
            if (value.first == nullptr || value.second <= 0)
            {
                return false;
            }
        }

        return true;
    }
    catch (...)
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

int CoreTools::SmartPointerManagerImpl::CopyIncreaseReference(const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (IsNullPtr(data))
    {
        return 0;
    }

    const auto iter = m_ReferenceContainer.find(data);

    if (iter != m_ReferenceContainer.cend())
    {
        return ++(iter->second);
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "ָ�벻�����ü��������С�");
        return -1;
    }
}

int CoreTools::SmartPointerManagerImpl::IncreaseReference(const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (IsNullPtr(data))
    {
        return 0;
    }

    const auto iter = m_ReferenceContainer.find(data);

    if (iter != m_ReferenceContainer.cend())
    {
        return ++(iter->second);
    }
    else
    {
        if (m_ReferenceContainer.insert({ data, 1 }).second)
            return 1;
        else
            return 0;
    }
}

int CoreTools::SmartPointerManagerImpl::DecreaseReference(const void* data)
{
    CORE_TOOLS_CLASS_IS_VALID_3;

    if (IsNullPtr(data))
    {
        return 0;
    }

    const auto iter = m_ReferenceContainer.find(data);

    if (iter != m_ReferenceContainer.cend())
    {
        if (--iter->second == 0)
        {
            m_ReferenceContainer.erase(iter);
            return 0;
        }
        else
        {
            return iter->second;
        }
    }
    else
    {
        CORE_TOOLS_ASSERTION_2(false, "ָ�벻�����ü��������С�");
        return -1;
    }
}

bool CoreTools::SmartPointerManagerImpl::IsSmartPointer(const void* data) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_3;

    if (IsNullPtr(data))
    {
        return false;
    }

    const auto iter = m_ReferenceContainer.find(data);

    if (iter != m_ReferenceContainer.cend())
        return true;
    else
        return false;
}

bool CoreTools::SmartPointerManagerImpl::IsNullPtr(const void* data) const noexcept
{
    if (data == nullptr)
        return true;
    else
        return false;
}
