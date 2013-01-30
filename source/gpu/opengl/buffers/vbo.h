#ifndef _H_PUNK_OPENGL_BUFFER
#define _H_PUNK_OPENGL_BUFFER

#include "../gl/module.h"

namespace GPU
{
	namespace OpenGL
	{
		class VideoMemory;

		class PUNK_ENGINE VertexBufferObject
		{
		public:
			
			void Create(void* data, size_t m_size);
			void Destroy();
			~VertexBufferObject();

			void Bind() const;
			void Unbind() const;

			void* Map();
			const void* Map() const;
			void Unmap() const;

			void CopyData(void* data, size_t size);

			bool IsValid() const;

			size_t GetSize() const { return m_size; }

		private:		

			//	Only VideoMemory can create it
			VertexBufferObject();

			VertexBufferObject(const VertexBufferObject&);
			VertexBufferObject& operator = (const VertexBufferObject&);
			
			GLuint m_index;
			size_t m_size;

			friend class VideoMemory;
		};
	}
}

#endif	//	_H_PUNK_OPENGL_BUFFER