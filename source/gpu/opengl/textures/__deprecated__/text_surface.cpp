#include "text_surface.h"
#include "../../common/video_driver.h"
#include "../../common/texture2d.h"
#include "../../../utility/fonts/font_builder.h"

namespace GPU
{
// TODO (chip#1#): Global variable should be removed
    Utility::FontBuilder g_font_builder;

	namespace OpenGL
	{
        TextSurface::TextSurface(VideoDriver* driver)
            : m_video_driver(driver)
		{
            m_texture = m_video_driver->CreateTexture2D(64, 64, ImageModule::IMAGE_FORMAT_RED, nullptr, false);
			m_halignment = TextHorizontalAlignment::HORIZONTAL_LEFT;
			m_valignment = TextVerticalAlignment::VERTICAL_TOP;
			m_font = L"times.ttf";
			m_font_size = 14;
			m_auto_wrap = false;
		}

		TextSurface::~TextSurface()
		{
			safe_delete(m_texture);
		}

		void TextSurface::SetSize(int width, int height)
		{
            m_texture->Resize(width, height);
		}

		int TextSurface::CalculateTextXOffset(const System::string& text)
		{
			int start_x;
			if (TextHorizontalAlignment::HORIZONTAL_LEFT == m_halignment)
				start_x = 0;
			else if (TextHorizontalAlignment::HORIZONTAL_CENTER == m_halignment)
			{
				int length = g_font_builder.CalculateLength(text.Data());
				if (length >= m_texture->GetWidth())
					start_x = 0;
				else
					start_x = (m_texture->GetWidth() - length) / 2;
			}
			else if (TextHorizontalAlignment::HORIZONTAL_RIGHT == m_halignment)
			{
				int length = g_font_builder.CalculateLength(text.Data());
				if (length >= m_texture->GetWidth())
					start_x = 0;
				else
					start_x = m_texture->GetWidth() - length;
			}
			return start_x;
		}

		int TextSurface::CalculateTextYOffset(const System::string& text)
		{
			const wchar_t* cur = text.Data();
			int length = g_font_builder.CalculateLength(cur);
			if (length == 0)
				return 1;
			int max_offset = g_font_builder.GetMaxOffset(text);
			int min_offset = g_font_builder.GetMinOffset(text);
			int max_height = max_offset - min_offset;
            //int max_lines = m_texture->GetHeight() / max_height;
			int req_lines = length / m_texture->GetWidth();
			int start_y = 0;
			if (TextVerticalAlignment::VERTICAL_BOTTOM == m_valignment)
			{
				start_y = 0;
			}
			else if (TextVerticalAlignment::VERTICAL_CENTER == m_valignment)
			{
				start_y = m_texture->GetHeight() / 2 + req_lines*max_height / 2;
			}
			else if (TextVerticalAlignment::VERTICAL_TOP == m_valignment)
			{
				start_y = max_offset;
			}
			return start_y;
		}

		bool TextSurface::RenderTextToTexture()
		{
			if (m_text.Length() == 0)
				if (m_texture)
					return (m_texture->Fill(0), true);

			int start_x, start_y;
			int x = start_x = CalculateTextXOffset(m_text);
			int y = start_y = CalculateTextYOffset(m_text);
			m_texture->Fill(0);
			g_font_builder.SetCurrentFace(m_font);
			g_font_builder.SetCharSize(m_font_size, m_font_size);
			for (const wchar_t* a = m_text.Data(); *a; a++)
			{
				int width;
				int height;
				int x_offset;
				int y_offset;
				int x_advance;
				int y_advance;
				unsigned char* buffer;
				g_font_builder.RenderChar(*a, &width, &height, &x_offset, &y_offset, &x_advance, &y_advance, &buffer);
				if (x_offset < 0 && x == 0)
					x += -x_offset;
				if (x + x_offset + width >= m_texture->GetWidth())
				{
					y -= g_font_builder.GetHeight(L'M');
					x = CalculateTextXOffset(a);
					if (y < 0)
						return true;
				}
				m_texture->CopyFromCPU(x + x_offset, y - y_offset, width, height, buffer);
				x += x_advance;
			}/**/
			return true;
		}

		void TextSurface::SetFont(const System::string& font)
		{
			m_font = font;
			RenderTextToTexture();
		}

		void TextSurface::SetTextSize(int size)
		{
			m_font_size = size;
			RenderTextToTexture();
		}

		bool TextSurface::SetText(const System::string& text)
		{
			m_text = text;
			return RenderTextToTexture();
		}


        bool TextSurface::Save(std::ostream&) const
		{
			return true;
		}

        bool TextSurface::Load(std::istream&)
		{
			return true;
		}
	}
}
