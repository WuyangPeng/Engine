// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:16)

#ifndef MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H
#define MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H

#include "Mathematics/MathematicsDll.h"
#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE UnorderedTriangleKey
    {
    public:
        using ClassType = UnorderedTriangleKey;
        
    public:
        UnorderedTriangleKey (int first, int second,int third) noexcept;
        
        UnorderedTriangleKey(const UnorderedTriangleKey& rhs) noexcept;
        UnorderedTriangleKey& operator =
        (const UnorderedTriangleKey& rhs) noexcept;
		
		~UnorderedTriangleKey()= default;
		UnorderedTriangleKey(UnorderedTriangleKey&& rhs) noexcept = default;
        UnorderedTriangleKey& operator =(UnorderedTriangleKey&& rhs) noexcept = default;
        
        CLASS_INVARIANT_DECLARE;
        
        int GetKey(int index) const;
        
    private:
        int m_Vertex[3];
    };
    
    bool MATHEMATICS_DEFAULT_DECLARE operator < (const UnorderedTriangleKey& lhs,  const UnorderedTriangleKey& rhs);
    
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_MESHES_UNORDERED_TRIANGLE_KEY_H



