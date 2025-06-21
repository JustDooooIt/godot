#ifndef __REMEMBEREDSET_H__
#define __REMEMBEREDSET_H__

#include <queue>

class RememberedSet {
};

class RememberedSetLog {
private:
	static thread_local std::queue<int> _rs_log;
};

class RememberedSetLogs {
private:
	std::queue<std::queue<int>> _rs_logs;
};

#endif // __REMEMBEREDSET_H__