// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∞Ê±æ£∫0.4.0.2 (2020/07/31 17:37)

#ifndef CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_H
#define CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_H

#include "CoreTools/CoreToolsDll.h"

#include <memory>

namespace CoreTools
{
    template <typename T>
    class WeakPtr
    {
    public:
        using ClassType = WeakPtr;

    public:
        explicit WeakPtr(uint64_t uniqueID);
        explicit WeakPtr(const std::shared_ptr<T>& ptr);

        CLASS_INVARIANT_DECLARE;

        uint64_t GetUniqueID() const;
        std::shared_ptr<T> GetPtr();

    private:
        uint64_t m_UniqueID;
        std::weak_ptr<T> m_WeakPtr;        
    };
}

#endif  // CORE_TOOLS_OBJECT_SYSTEMS_WEAK_PTR_H
