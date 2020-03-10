// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/10 09:33)

#ifndef MATHEMATICS_QUERY_QUERY_H
#define MATHEMATICS_QUERY_QUERY_H

#include "Mathematics/MathematicsDll.h"

#include "Flags/QueryType.h"

namespace Mathematics
{
    class MATHEMATICS_DEFAULT_DECLARE QueryBase
    {
    public:
        using ClassType = QueryBase;
     
	public:
        QueryBase ();   
        virtual ~QueryBase ();
 
		CLASS_INVARIANT_VIRTUAL_DECLARE;
        
        virtual QueryType GetType () const = 0;   
    };
}

#endif // MATHEMATICS_QUERY_QUERY_H
