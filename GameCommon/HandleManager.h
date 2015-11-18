#pragma once

#include "Handle.h"

class HandleManager
{
public:
	enum { MaxEntries = 4096 }; // 2^12

	HandleManager();

	void Reset();
	Handle Add(void* p, uint32_t type);
	void Update(Handle handle, void* p);
	void Remove(Handle handle);

	void* Get(Handle handle) const;
	bool Get(Handle handle, void*& out) const;
	template< typename T > bool GetAs(Handle handle, T& out) const;

	int GetCount() const;

private:
	HandleManager(const HandleManager&);
	HandleManager& operator=(const HandleManager&);

	struct HandleEntry
	{
		HandleEntry();
		explicit HandleEntry(uint32_t nextFreeIndex);

		uint32_t m_nextFreeIndex : 12;
		uint32_t m_counter : 15;
		uint32_t m_active : 1;
		uint32_t m_endOfList : 1;
		void* m_entry;
	};

	HandleEntry m_entries[MaxEntries];

	int m_activeEntryCount;
	uint32_t m_firstFreeEntry;
};


template< typename T >
inline bool HandleManager::GetAs(Handle handle, T& out) const
{
	void* outAsVoid;
	const bool rv = Get(handle, outAsVoid);
	out = union_cast<T>(outAsVoid);

	return rv;
}
