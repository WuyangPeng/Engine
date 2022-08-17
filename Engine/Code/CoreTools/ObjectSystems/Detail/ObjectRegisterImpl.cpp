///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/24 23:03)

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

int64_t CoreTools::ObjectRegisterImpl::GetUniqueID(const ConstObjectInterfaceSharedPtr& object) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto& container = registered.get<UniqueObject>();

    const auto iter = container.find(object);

    if (iter != container.cend())
    {
        return iter->associated;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("objectָ��û��ע�ᣡ"s));
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

    const auto& container = registered.get<UniqueObject>();

    if (container.find(object) == container.cend())
    {
        // ���Ƕ����һ����ͼ�������������
        // ������Ҫʹ���ء���������ϵͳ��������д��һ��Ψһ�ı�ʶ�������̡���򵥵ľ���д����ĵ�ַ��
        // �������ǿ���ʹ��Object::Save������һ���ַ��set�У���ע�ᡱ�����������������⣺

        // 1. ��ַ������Ӧ�ó�������ʱ�ı䡣�������У���ͬ�ĳ���ͼ�����²�ͬ�Ķ��������
        // ��Ϊ�ڡ�ע�ᡱ��ַ��˳�����˱仯��һ����������Ǵ洢��ַ�����飨ordered�����������洢˳���������С�

        // 2. ��ʹ�����˶����˳���������У���ͬ�ĳ���ͼ�������ļ������ֽ�ƥ�䡣��ַ����ı䡣
        // һ������취��ָ��һ���������ַ����ÿ��������Ϊ����ע�ᡣ��򵥵ľ���ʹ�á�ordered�������������
        // Ϊ�˱������ַ����ָ��֮��Ļ���������ʹ�������������������һ��

        auto uniqueID = registered.size() + 1;

        registered.emplace_back(object, uniqueID);

        return uniqueID;
    }
    else
    {
        return 0;
    }
}
