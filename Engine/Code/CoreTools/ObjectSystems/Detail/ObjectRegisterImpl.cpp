/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:23)

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

    if (const auto iter = container.find(object);
        iter != container.cend())
    {
        return iter->associated;
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("object指针没有注册！"s))
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

    if (const auto& container = registered.get<UniqueObject>();
        container.find(object) == container.cend())
    {
        /// 这是对象第一次在图表对象中遇到。
        /// 我们需要使加载——连接器系统正常工作写入一个唯一的标识符到磁盘。最简单的就是写对象的地址，
        /// 所以我们可以使用Object::Save保存在一组地址在set中（“注册”）。但这有两个问题：

        /// 1. 地址在两次应用程序运行时改变。两次运行，相同的场景图将导致不同的对象的排序，
        /// 因为在“注册”地址的顺序发生了变化。一个解决方案是存储地址的数组（ordered）并保存对象存储顺序在数组中。

        /// 2. 即使保障了对象的顺序，两次运行，相同的场景图将导致文件不逐字节匹配。地址本身改变。
        /// 一个解决办法是指定一个“虚拟地址”到每个对象，因为它被注册。最简单的就是使用“ordered”对象的索引。
        /// 为了避免零地址和零指数之间的混淆，我们使用索引是数组的索引加一。

        const auto uniqueId = registered.size() + 1;

        registered.emplace_back(object, uniqueId);

        return uniqueId;
    }
    else
    {
        return 0;
    }
}
