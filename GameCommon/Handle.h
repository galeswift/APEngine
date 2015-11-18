#pragma once

#include <cstdint>

struct Handle
{
	Handle() : m_index(0), m_counter(0), m_type(0)
	{}

	Handle(uint32_t index, uint32_t counter, uint32_t type)
		: m_index(index), m_counter(counter), m_type(type)
	{}

	inline operator uint32_t() const;

	uint32_t m_index : 12;
	uint32_t m_counter : 15;
	uint32_t m_type : 5;
};

Handle::operator uint32_t() const
{
	return m_type << 27 | m_counter << 12 | m_index;
}