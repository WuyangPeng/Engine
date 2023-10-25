///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/09/20 15:34)

#include "CoreTools/CoreToolsExport.h"

#include "ObjectRegisterImpl.h"
#include "TopLevel.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

CoreTools::ObjectRegisterImpl::ObjectRegisterImpl() noexcept
    : registered{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, ObjectRegisterImpl)

int64_t CoreTools::ObjectRegisterImpl::GetUniqueId(const ConstObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto& container = registered.get<UniqueObject>();

    if (const auto iter = container.find(object); iter != container.cend())
    {
        return iter->associated;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("objectָ��û��ע�ᣡ"s))
    }
}

int CoreTools::ObjectRegisterImpl::GetOrderedSize() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(registered.size());
}

CoreTools::ConstRegisterContainerConstIter CoreTools::ObjectRegisterImpl::begin() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return registered.begin();
}

CoreTools::ConstRegisterContainerConstIter CoreTools::ObjectRegisterImpl::end() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    return registered.end();
}

int64_t CoreTools::ObjectRegisterImpl::RegisterRoot(const ConstObjectInterfaceSharedPtr& object)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    if (const auto& container = registered.get<UniqueObject>(); container.find(object) == container.cend())
    {
        // ���Ƕ����һ����ͼ�������������
        // ������Ҫʹ���ء���������ϵͳ��������д��һ��Ψһ�ı�ʶ�������̡���򵥵ľ���д����ĵ�ַ��
        // �������ǿ���ʹ��Object::Save������һ���ַ��set�У���ע�ᡱ�����������������⣺

        // 1. ��ַ������Ӧ�ó�������ʱ�ı䡣�������У���ͬ�ĳ���ͼ�����²�ͬ�Ķ��������
        // ��Ϊ�ڡ�ע�ᡱ��ַ��˳�����˱仯��һ����������Ǵ洢��ַ�����飨ordered�����������洢˳���������С�

        // 2. ��ʹ�����˶����˳���������У���ͬ�ĳ���ͼ�������ļ������ֽ�ƥ�䡣��ַ����ı䡣
        // һ������취��ָ��һ���������ַ����ÿ��������Ϊ����ע�ᡣ��򵥵ľ���ʹ�á�ordered�������������
        // Ϊ�˱������ַ����ָ��֮��Ļ���������ʹ�������������������һ��

        const auto uniqueId = registered.size() + 1;

        registered.emplace_back(object, uniqueId);

        return uniqueId;
    }
    else
    {
        return 0;
    }
}
