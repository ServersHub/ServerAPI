#pragma once

#include <vector>

#include "json.hpp"

namespace API
{
	void MergePdbConfig(nlohmann::json& left, const nlohmann::json& right);
	std::vector<std::string> MergeStringArrays(std::vector<std::string> first, std::vector<std::string> second);

	__forceinline std::string ReplaceString(std::string subject, const std::string& search, const std::string& replace)
	{
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos)
		{
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}

		return subject;
	}
} // namespace API
