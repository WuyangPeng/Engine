/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 22:16)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_FWD_H
#define CORE_TOOLS_OBJECT_SYSTEMS_FWD_H

#include "CoreTools/Helper/SharedPtrMacro.h"

#include <memory>

namespace CoreTools
{
    class ObjectRegister;
    class BufferTarget;
    class BufferSource;
    class ObjectLink;
    class ObjectInterface;
    class Object;

    class InitTermContainer;
    class InitTerm;
    class Rtti;
    class ObjectName;

    template <typename T, typename Enable>
    struct StreamSize;

    class Stream;
    class OutTopLevel;
    class InTopLevel;
    struct UniqueObject;

    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct ObjectAssociated;

    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct ConstObjectAssociated;

    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct WeakObjectAssociated;

    template <typename T>
    requires(std::is_base_of_v<ObjectInterface, T>)
    struct ConstWeakObjectAssociated;

    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectRegister);
    CORE_TOOLS_SHARED_PTR_DECLARE(BufferTarget);
    CORE_TOOLS_SHARED_PTR_DECLARE(BufferSource);
    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectLink);
    CORE_TOOLS_SHARED_PTR_DECLARE(ObjectInterface);
    CORE_TOOLS_SHARED_PTR_DECLARE(Object);

    class BufferOutStream;
    class FileOutStream;
    class BufferInStream;
    class FileInStream;
    class ObjectManager;
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_FWD_H