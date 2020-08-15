// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/16 11:14)

#ifndef MATHEMATICS_MESHES_EDGE_KEY_H
#define MATHEMATICS_MESHES_EDGE_KEY_H

#include "Mathematics/MathematicsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <iosfwd>
 #include "System/Helper/PragmaWarning.h"
    #include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE EdgeKey
    {
    public:
        typedef EdgeKey ClassType;
        
    public:
        EdgeKey (int first, int second) noexcept;
		EdgeKey() noexcept;
        
        EdgeKey(const EdgeKey& rhs) noexcept;
        EdgeKey& operator = (const EdgeKey& rhs) noexcept;
		
		~EdgeKey() = default;
		EdgeKey(EdgeKey&& rhs) = default;
        EdgeKey& operator = (EdgeKey&& rhs) = default;
        
		CLASS_INVARIANT_DECLARE;
        
        int GetKey(int index) const;
		void SetKey(int index,int value);
        
    private:
        int m_Vertex[2];
    };
    
    bool MATHEMATICS_DEFAULT_DECLARE operator< (const EdgeKey& lhs,  const EdgeKey& rhs);
    
	MATHEMATICS_DEFAULT_DECLARE System::OStream& operator<<(System::OStream& os, const EdgeKey& edgeKey);
}
#include STSTEM_WARNING_POP

#endif // MATHEMATICS_MESHES_EDGE_KEY_H