#include "../../system/logger.h"
#include "../../system/binary_file.h"
#include "../../system/environment.h"
#include "terrain_loader.h"

namespace Virtual
{
	TerrainLoader::TerrainLoader(const System::string& map_name, const Math::ivec2& block)
		: m_map_name(map_name)
		, m_block(block)
		, m_data(nullptr)
	{}

	System::StreamingStepResult TerrainLoader::Load()
	{
		System::string filename = System::Environment::Instance()->GetMapFolder() + m_map_name + L"\\" + System::string::Format(L"%d_%d.raw", m_block.X(), m_block.Y());
		
		System::Buffer buffer;
		if (!System::BinaryFile::Load(filename, buffer))
			return (out_error() << "Can't load " << filename << std::endl, System::STREAM_ERROR);
		m_size = buffer.GetSize();
		m_data = buffer.Release();
		return System::STREAM_OK;
	}

	System::StreamingStepResult TerrainLoader::Decompress(void** data, unsigned* size)
	{
		*data = m_data;
		*size = m_size;
		return System::STREAM_OK;
	}

	System::StreamingStepResult TerrainLoader::Destroy()
	{
		return System::STREAM_OK;
	}

	TerrainLoader::~TerrainLoader()
	{
		//	it's ok, i hope. better call destroy separately
		Destroy();
	}
}