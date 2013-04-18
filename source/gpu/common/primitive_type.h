#ifndef _H_PUNK_GPU_PRIMITIVE_TYPE
#define _H_PUNK_GPU_PRIMITIVE_TYPE

namespace GPU
{
	enum class PrimitiveType { 
		POINTS, 
		LINE_STRIP, 
		LINE_LOOP, 
		LINES, 
		LINE_STRIP_ADJANCECY, 
		LINES_ADJANCENCY, 
		TRIANGLE_STRIP,
		TRIANGLE_FAN,
		TRIANGLES,
		TRIANGLE_STRIP_ADJANCECY,
		TRIANGLES_ADJANCECY
	};
}

#endif	//	_H_PUNK_GPU_PRIMITIVE_TYPE